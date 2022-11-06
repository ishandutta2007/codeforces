#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int l[N],r[N],v[N];
int t[N],a[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&l[i],&r[i],&v[i]);
    for(int d=0;d<=30;d++)
    {
        for(int i=1;i<=n;i++) t[i]=0;
        for(int i=1;i<=m;i++)
        if((v[i]>>d)&1) t[l[i]]++,t[r[i]+1]--;
        for(int i=1;i<=n;i++) t[i]+=t[i-1];
        for(int i=1;i<=n;i++) t[i]=!!t[i];
        for(int i=1;i<=n;i++) a[i]|=t[i]<<d;
        for(int i=1;i<=n;i++) t[i]+=t[i-1];
        for(int i=1;i<=m;i++)
        if(!((v[i]>>d)&1) && t[r[i]]-t[l[i]-1]==r[i]-l[i]+1){puts("NO");return 0;}
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}