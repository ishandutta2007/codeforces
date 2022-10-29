#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
int dp[550000];  
int main()  
{  
    int n,k,i,a,sum,j;  
    while(~scanf("%d%d",&n,&k))  
    {  
        memset(dp,0,sizeof(dp));  
        sum=0;  
        dp[0]=1;  
        for(i=0;i<n;i++)  
        {  
            scanf("%d",&a);  
            sum+=a;  
            for(j=sum;j>=a;j--)  
            {  
                if(dp[j-a]!=0)dp[j]=1;  
            }  
        }  
        int st;  
        st=0;  
        int now;  
        now=0;  
        int ss;  
        ss=0;  
        while(1)  
        {  
            now=now+k;  
            for(i=0;i<k;i++)  
            {  
                if(dp[now-i])break;  
            }  
            if(i==k)break;  
            now=now-i;  
            ss++;  
        }  
        cout<<now-k<<" "<<ss<<endl;  
    }  
}