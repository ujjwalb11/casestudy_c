#include<stdio.h>
#define size 3
#define id 2
#define p_lower 0
#define p_upper 25000
#define p1_lower 0
#define p1_upper 26000
#define min_storage 3

enum{samsung,xiomi,asus};
struct mobilephone
{
    int modelid;
    char modelname[20];
    double displaysize;
    int batterycapacity;
    double rammemory;
    double intmemory;
    int camresolution;
    double price;
};

typedef struct mobilephone mob;

void displayone(const mob*);
void displaymodel(const mob*,int,int);
double priceavg(const mob*,int);
int maxbattery(const mob*,int);
int maxcamres(const mob*,int,int,int);
int modelcount(const mob*,int,int,int);
int modelminstor(const mob*,int,int);


int main()
{
    double max,avg;
    mob marr[3]={{1,"samsung",5,2000,2,3,8,10000},{2,"xiomi",6,3000,3,4,16,20000},{3,"asus",7,4000,4,5,32,30000}};

    displaymodel(marr,size,id);

    avg=priceavg(marr,size);
    printf("\n%lf\n",avg);
    maxbattery(marr,size);
    maxcamres(marr,size,p_lower,p_upper);
    //printf("\nmodel with max cam resolution between given price range: %s\n",model1);
    modelcount(marr,size,p1_lower,p1_upper);
    //printf("\nnumber of models between given price range: %d\n",count);
    modelminstor(marr,size,min_storage);
    //printf("\nmodels with min given storage: %d",count1)


}

void displayone(const mob*ptr)
{
    printf("\n1. modelno. = %d\n2. modelname = %s\n3. displaysize = %lf\n4. batterycapacity = %d\n5. rammemory = %lf\n6. intmemory = %lf\n7. camresolution = %d\n8. price = %lf\n",ptr->modelid,ptr->modelname,ptr->displaysize,ptr->batterycapacity,ptr->rammemory,ptr->intmemory,ptr->camresolution,ptr->price);
}

void displaymodel(const mob*ptr,int n,int x)
 {
     const mob*parr=ptr;
     int i=0;
     for(i=0;i<n;i++)
     {
         if (parr->modelid == x)
         {
             displayone(parr);
         }
         parr++;
     }
 }

double priceavg(const mob*ptr,int n)
{
    const mob*parr=ptr;
    double sum=0,avg;
    int i;
    for(i=0;i<n;i++)
    {
        sum=sum+parr->price;
        parr++;
    }
avg=(sum)/n;
return avg;
}

int maxbattery(const mob*ptr,int n)
{
    const mob*parr=ptr;
    double max=parr->batterycapacity;
    int i;
    int model;
    for(i=0;i<n;i++)
    {
        if(parr->batterycapacity>max)
        {
            model=parr->modelid;
            parr++;
        }
    }
    printf("modelid with max battery: %d",model);
}

int maxcamres(const mob*ptr,int s,int n,int m)
{
    const mob*parr=ptr;
    double max1=parr->camresolution;
    int i;
    int model1;
    for(i=0;i<s;i++)
    {
        if(parr->price<m && parr->price>n)

        {
            if(parr->camresolution>max1)
            {
                model1=parr->modelid;
            }
        }
    parr++;
    }
    printf("\nmodelid with max cam res: %d\n",model1);
}

int modelcount(const mob*ptr,int s,int n,int m)
{
    const mob*parr=ptr;
    int i;
    int count=0;
    for(i=0;i<s;i++)
    {
        if(parr->price<m && parr->price>n)
        {
            count++;
        }
    parr++;
    }
printf("\nno of models in given price range: %d\n",count);
}

int modelminstor(const mob*ptr,int s,int n)
{
    const mob*parr=ptr;
    int i;
    int count1=0;
    for(i=0;i<s;i++)
    {
        if(parr->intmemory==n || parr->intmemory>n)
        {
            count1++;
        }
    parr++;
    }
printf("\nno of models in given min storage: %d\n",count1);

}





















