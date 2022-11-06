#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define inf 0x3f3f3f3f
using namespace std;
int n;
int x[N],f[N][2][2];
char s[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        for(int i=0;i<=n;i++) memset(f[i],0x3f,sizeof(f[i]));
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++) f[1][i][j]=i+j;
        for(int i=2;i<=n;i++)
        {
            f[i][0][1]=min(f[i-1][0][0],f[i-1][1][0])+1;
            f[i][1][1]=min(f[i-1][1][1],f[i-1][0][1])+1;
            if(s[i]==s[i-2]) f[i][0][0]=s[i]==s[i-1]?inf:f[i-1][1][0], f[i][1][0]=f[i-1][1][1];
            else if(s[i]==s[i-1]) f[i][1][0]=min(f[i-1][1][1],f[i-1][0][1]);
            else f[i][1][0]=min(f[i-1][1][1],f[i-1][0][1]), f[i][0][0]=min(f[i-1][1][0],f[i-1][0][0]);
        }
        int ans=inf;
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++) ans=min(ans,f[n][i][j]);
        printf("%d\n",ans);
    }
    return 0;
}