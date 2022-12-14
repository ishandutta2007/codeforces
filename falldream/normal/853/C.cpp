#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,q,R[MN+5],cnt=0,rt[MN+5],Rt[MN+5];
struct Tree{int l,r,x;}T[MN*100+5];

int Query(int x,int nx,int v)
{
    int sum=0,l=1,r=n,mid;
    while(l<r)
    {
        mid=l+r>>1;
        if(v<=mid) x=T[x].l,nx=T[nx].l,r=mid;
        else sum+=T[T[nx].l].x-T[T[x].l].x,x=T[x].r,nx=T[nx].r,l=mid+1;
    }
    return sum+T[nx].x-T[x].x;
}

void Modify(int x,int nx,int v)
{
    int l=1,r=n,mid;T[nx].x=T[x].x+1;
    while(l<r)
    {
        mid=l+r>>1;
        if(v<=mid) T[nx].r=T[x].r,T[nx].l=++cnt,x=T[x].l,nx=T[nx].l,r=mid;
        else T[nx].l=T[x].l,T[nx].r=++cnt,x=T[x].r,nx=T[nx].r,l=mid+1;
        T[nx].x=T[x].x+1;
    }
}

int main()
{
    n=read();q=read();
    for(int i=1;i<=n;++i)
    {
        int x=read();R[x]=i;
        Modify(rt[i-1],rt[i]=++cnt,x);
    }
   // for(int i=1;i<=n;++i) Rt[i]=Modify(Rt[i-1],Rt[i]=++cnt,R[i]);
    for(int i=1;i<=q;++i)
    {
        int l=read(),d=read(),r=read(),u=read();long long ans=1LL*n*(n-1)/2;
        int U=n-u,D=d-1,L=l-1,R=n-r;
        int ru=0,rd=0,lu=0,ld=0;
        if(l>1&&u<n) lu=l-1-Query(0,rt[l-1],u);
        if(l>1&&d>1) ld=Query(0,rt[l-1],d-1);
        if(r<n&&u<n) ru=n-r-Query(rt[r],rt[n],u);
        if(r<n&&d>1) rd=Query(rt[r],rt[n],d-1);
        ans-=1LL*U*(U-1)/2;ans-=1LL*D*(D-1)/2;
        ans-=1LL*L*(L-1)/2;ans-=1LL*R*(R-1)/2;
        ans+=1LL*lu*(lu-1)/2;ans+=1LL*ld*(ld-1)/2;
        ans+=1LL*ru*(ru-1)/2;ans+=1LL*rd*(rd-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}