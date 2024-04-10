#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
char str[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        scanf("%s",str+1);
        int n=strlen(str+1);
        int ans=n;
        for(int i=0;i<=9;i++)
        {
            int res=0;
            for(int j=1;j<=n;j++)
            if(str[j]==i+'0') res++;
            ans=min(ans,n-res);
        }
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
            if(i!=j)
            {
                int u=j,cnt=0;
                for(int k=1;k<=n;k++)
                if((str[k]-'0'==i && u!=i) || (str[k]-'0'==j && u!=j)) ++cnt,u=str[k]-'0';
                cnt=cnt/2*2;
                ans=min(ans,n-cnt);
            }
        printf("%d\n",ans);
    }
    return 0;
}