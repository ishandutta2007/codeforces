#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
int main()  
{  
    int k,a,b,v,mb,ma,num;  
    while(scanf("%d%d%d%d",&k,&a,&b,&v)!=EOF)  
    {  
        mb=b/(k-1);
        num=k*v;
        if(mb*num>=a)  
        {  
            if(a%num==0)  
            {  
                printf("%d\n",a/num);  
            }  
            else  
            {  
                printf("%d\n",a/num+1);  
            }  
        }  
        else  
        {  
            int cnt=mb;  
            int sum=a-mb*num;  
            if(b-mb*(k-1)>0)  
            {  
                sum=sum-(b-mb*(k-1)+1)*v;  
                mb++;  
            }  
            if(sum>0)  
            {  
                if(sum%v==0)  
                {  
                    mb+=sum/v;  
                }  
                else  
                {  
                    mb+=sum/v;  
                    mb++;  
                }  
            }  
            printf("%d\n",mb);  
        }  
    }  
    return 0;  
}