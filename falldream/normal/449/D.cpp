#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define MN 1048576
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],f[22][MN+5],pw[MN+5];

void FWT(int d,int l,int r)
{
    if(l==r){f[d][l]=a[l];return;}
    int mid=l+r>>1;FWT(d+1,l,mid);FWT(d+1,mid+1,r);
    for(int i=0;i<=mid-l;++i) f[d][l+i]=(f[d+1][l+i]+f[d+1][mid+1+i])%mod,f[d][mid+1+i]=f[d+1][mid+1+i];
}

void fwt(int l,int r)
{
    if(l==r) return;
    int mid=l+r>>1;fwt(l,mid);fwt(mid+1,r);
    for(int i=0;i<=mid-l;++i) a[l+i]=(a[l+i]-a[mid+1+i]+mod)%mod;
}

int main()
{
    n=read();pw[0]=1;
    for(int i=1;i<=n;++i) ++a[read()];
    FWT(1,0,MN-1);
    for(int i=1;i<=n;++i) pw[i]=pw[i-1]*2%mod;
    for(int i=0;i<MN;++i) a[i]=pw[f[1][i]];
    fwt(0,MN-1);printf("%d\n",a[0]);
    return 0;
}