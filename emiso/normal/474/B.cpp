//EM NOME DE ABELLA
#include <stdio.h>

int a[100002];
//0 1  2  3  4  5
//1 2  3  4  5  6
void bs(int n,int t)
{
     int i=0;
     int f=t;
     int m=(i+t)/2;
     while(f-i>1)
     {
               m=(i+f)/2;
               if(a[m]>n)
               {
                         f=m;
               }
               else if(a[m]<n)
               {
                         i=m;
               }
               else
               {   
                    i=m;
                    break;
               }
     }
     printf("%d\n",i+1);
}

int main()
{
    int n,j,ju,i,c=1;
    scanf("%d",&n);
    a[0]=1;
    for(i=1;i<=n;i++)
    {
                    scanf("%d",&ju);
                    if(i>0) a[i]=a[i-1]+ju;
    }
    
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
                    scanf("%d",&ju);
                    bs(ju,n);
    }
    return 0;
}