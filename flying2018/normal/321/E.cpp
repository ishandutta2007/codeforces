#include<iostream>
#include<cstdio>
#include<cstring>
#define N 4010
using namespace std;
int a[N][N],s[N][N];
int read()
{
    int ch=0,x=0;
    for(ch=getchar();ch<'0' || ch>'9';ch=getchar());
    for(;ch>='0' && ch<='9';ch=getchar()) x=x*10+(ch-'0');
    return x;
}
long long f[N];
int g[N];
int t,n;
void work(int x)
{
    g[0]=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+x,g[i]=g[i-1]+1;
        for(int j=0;j<i-1;j++)
        if(f[j]+s[j+1][i]+x<f[i] || (f[j]+s[j+1][i]+x==f[i] && g[j]+1<g[i])) f[i]=f[j]+s[j+1][i]+x,g[i]=g[j]+1;
    }
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j]=read();
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) s[i][j]=s[i][j-1]+a[i][j];
    for(int i=n;i>=1;i--)
        for(int j=i;j<=n;j++) s[i][j]+=s[i+1][j];
    int l=-1e9,r=1e9,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        work(mid);
        if(g[n]==m){printf("%d",f[n]-m*mid);return 0;}
        if(g[n]<=m) r=mid-1,ans=f[n]-mid*m;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}