#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define ll long long
#define inf 1200000000000000000
using namespace std;
int n;ll k;
ll f[70];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        memset(f,0,sizeof(f));
        scanf("%d%lld",&n,&k);
        f[0]=1;
        for(int i=1;i<=min(n,64);i++)
            for(int j=1;j<=i;j++) f[i]=min(f[i]+f[i-j],inf);
        int u=min(n,64);
        if(f[u]<k){puts("-1");continue;}
        for(int i=1;i<=n-u;i++) printf("%d ",i);
        int t=n-u+1;
        for(int i=u-1;i>=0;i--)
        if(k>f[i]) k-=f[i];
        else
        {
            for(int j=i+1;j<=u;j++) printf("%d ",t+u-j);
            t+=u-i;
            u=i;
        }
        while(t<=n) printf("%d ",t),t++;
        puts("");
    }
    return 0;
}