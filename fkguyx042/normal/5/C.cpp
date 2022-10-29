#include<iostream>  
#include<cstring>  
#include<cstdio>  
#include<cmath>  
using namespace std;  
int ans,key,dp[1000012];  
char s[1000012];  
int main()  
{  
    while(scanf("%s",&s)!=EOF)  
    {  
        int i,j,len=strlen(s);  
        dp[0]=0;  
        ans=0,key=1;  
        for(i=1; i<len; i++)  
        {  
            dp[i]=0;  
            if(i-dp[i-1]-1>=0&&s[i]==')'&&s[i-dp[i-1]-1]=='(')  
            {  
                dp[i]=dp[i-1]+2;  
                if(i-dp[i-1]-2>=0&&dp[i-dp[i-1]-2])  
                {  
                    dp[i]+=dp[i-dp[i-1]-2];  
                }  
            }  
            if(ans<dp[i]) ans=dp[i],key=1;  
            else if(ans==dp[i]&&ans) key++;  
        }  
        cout<<ans<<" "<<key<<endl;  
    }  
    return 0;  
}