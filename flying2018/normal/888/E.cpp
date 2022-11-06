#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 18
using namespace std;
int f[1<<N|1],ft,g[1<<N|1],gt;
int a[N*2];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int n0=n/2;
    f[1]=0;ft=1;
    for(int i=1;i<=n0;i++)
    {
        for(int j=1;j<=ft;j++) f[j+ft]=(f[j]+a[i])%m;
        ft=ft*2;
    }
    g[1]=0;gt=1;
    for(int i=n0+1;i<=n;i++)
    {
        for(int j=1;j<=gt;j++) g[j+gt]=(g[j]+a[i])%m;
        gt=gt*2;
    }
    sort(f+1,f+ft+1);
    sort(g+1,g+gt+1);
    int ans=max(*max_element(f+1,f+ft+1),*max_element(g+1,g+gt+1));
    int r=gt;
    for(int l=1;l<=ft;l++)
    {
        while(f[l]+g[r]>=m) r--;
        ans=max(ans,f[l]+g[r]);
    }
    printf("%d\n",ans);
    return 0;
}