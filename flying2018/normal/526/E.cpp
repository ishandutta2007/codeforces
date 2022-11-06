#include<iostream>
#include<cstdio>
#include<cstring>
#define N 2000010
#define ll long long
using namespace std;
int a[N*2],f[N],n;
int work(int p)
{
    int c=0;
    for(int i=p;i<n+p;c++) i=(i<=n?f[i]:f[i-n]+n)+1;
    return c;
}
int main()
{
    int q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i+2*n]=a[i+n]=a[i];
    while(q --> 0)
    {
        ll s=0,m;
        scanf("%lld",&m);
        for(int i=1;i<=2*n;i++)
        {
            f[i]=f[i-1];s-=a[i-1];
            if(f[i]<i) f[i]=i,s=a[i];
            while(f[i]<=3*n && s+a[f[i]+1]<=m) s+=a[++f[i]];
        }
        int id=1;
        for(int i=1;i<=n;i++)
        if(f[i]-i<=f[id]-id) id=i;
        int mn=n;
        for(int i=id;i<=f[id]+1;i++) mn=min(mn,work(i));
        printf("%d\n",mn);
    }
    return 0;
}