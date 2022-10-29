#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
int a[150000];  
bool cmp(int a,int b)  
{  
    return a>b;  
}  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        int sum=0,i,b[10],t=0;  
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
            sum+=a[i];  
            b[a[i]]++;
            if(a[i]==0) t++;  
        }  
        if(t==0)  
          printf("-1\n");  
        else if(t==n||(sum%3!=0&&t==n-1))  
          printf("0\n");  
        else  
        {  
            sort(a+1,a+n+1,cmp);  
            if(sum%3==0)  
            {  
                for(i=1;i<=n;i++)  
                  printf("%d",a[i]);  
                printf("\n");  
            }  
            else  
            {  
                int p=sum%3;  
                if(b[p]!=0||b[p+3]!=0||b[p+6]!=0)  
                {  
                    int t1,p1=0,p2=0; 
                    if(b[p]!=0)   t1=p;  
                    else if(b[p+3]!=0)  t1=p+3;  
                    else if(b[p+6]!=0)  t1=p+6;  
                    for(i=1;i<=n;i++)  
                    {  
                        if(a[i]==t1&&p1==0)     {p1=1;}  
                        else if(a[i]==0&&p2==0) {printf("0");p2=1;}  
                        else if(a[i]==0&&p2==1)  {continue;}  
                        else                   {printf("%d",a[i]);p2=2;}  
                    }  
                }  
                else  
                {  
                    int t2,t3,q1=0,q2=0,q3=0;
                    int m=(p+p)%3;  
                    if(b[m]>=2)   t2=t3=m;  
                    else if(b[m]==1&&b[m+3]>0)   {t2=m;t3=m+3;}  
                    else if(b[m+3]>=2)  t2=t3=m+3;  
                    else if(b[m+3]==1&&b[m+6]>0)  {t2=m+3;t3=m+6;}  
                    else                t2=t3=m+6;  
                    for(i=1;i<=n;i++)  
                    {  
                        if(a[i]==t2&&q1==0)  {q1=1;continue;}  
                        else if(a[i]==t3&&q2==0) {q2=1;continue;}  
                        else  
                        {  
                            if(a[i]==0&&q3==0)  {printf("0");q3=1;}  
                            else if(a[i]==0&&q3==1) {continue;}  
                            else   {printf("%d",a[i]);q3=2;}  
                        }  
                    }  
                }  
                printf("\n");  
            }  
        }  
    }  
    return 0;  
}