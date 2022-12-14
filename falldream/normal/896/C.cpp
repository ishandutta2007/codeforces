#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,V,o,top,a[MN+5];
pair<long long,int>q[MN+5];
struct Tree{int l,r,fg;long long x;int tag;long long val;}T[MN*4+5];
inline int rnd()
{
    int res=o;
    o=(7LL*o+13)%1000000007;
    return res;
}
inline void update(int x)
{
    T[x].x=T[x<<1].x;
    T[x].fg=(T[x<<1].fg&T[x<<1|1].fg&&T[x<<1].x==T[x<<1|1].x);
}
void Build(int x,int l,int r)
{
    if((T[x].l=l)==(T[x].r=r)){T[x].fg=1;T[x].x=a[l];T[x].tag=0;T[x].val=0;return;}
    int mid=l+r>>1;
    Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
    update(x);
}
inline void MarkA(int x,long long y){T[x].val+=y;T[x].x+=y;}
inline void MarkM(int x,long long y){T[x].tag=1;T[x].val=y;T[x].x=y;T[x].fg=1;}
inline void pushdown(int x)
{
    if(T[x].tag) MarkM(x<<1,T[x].val),MarkM(x<<1|1,T[x].val);
    else if(T[x].val) MarkA(x<<1,T[x].val),MarkA(x<<1|1,T[x].val);
    T[x].val=T[x].tag=0;
}
void Add(int x,int l,int r,int v)
{
   // cout<<"Add"<<x<<" "<<l<<" "<<r<<" "<<v<<endl;
    if(T[x].l==l&&T[x].r==r) {MarkA(x,v);return;}
    int mid=T[x].l+T[x].r>>1;pushdown(x);
    if(r<=mid) Add(x<<1,l,r,v);
    else if(l>mid) Add(x<<1|1,l,r,v);
    else Add(x<<1,l,mid,v),Add(x<<1|1,mid+1,r,v);
    update(x);
}
void Mod(int x,int l,int r,int v)
{
 //   cout<<"Mod"<<x<<" "<<l<<" "<<r<<" "<<v<<endl;
    if(T[x].l==l&&T[x].r==r) {MarkM(x,v);return;}
    int mid=T[x].l+T[x].r>>1;pushdown(x);
    if(r<=mid) Mod(x<<1,l,r,v);
    else if(l>mid) Mod(x<<1|1,l,r,v);
    else Mod(x<<1,l,mid,v),Mod(x<<1|1,mid+1,r,v);
    update(x);
}
void GetIt(int x,int l,int r)
{
    if(T[x].l==l&&T[x].r==r)
    {
        if(T[x].fg)q[++top]=make_pair(T[x].x,T[x].r-T[x].l+1);
        else
        {
            int mid=l+r>>1;pushdown(x);
            GetIt(x<<1,l,mid);
            GetIt(x<<1|1,mid+1,r);
        }
        return;
    }
    int mid=T[x].l+T[x].r>>1;pushdown(x);
    if(r<=mid) GetIt(x<<1,l,r);
    else if(l>mid) GetIt(x<<1|1,l,r);
    else GetIt(x<<1,l,mid),GetIt(x<<1|1,mid+1,r);
}
int pow(int x,int k,int mod)
{
    int sum=1%mod;
    for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) sum=1LL*sum*x%mod;
    return sum;
}
int main()
{
    n=read();m=read();o=read();V=read();
    for(int i=1;i<=n;++i) a[i]=rnd()%V+1;Build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1;
        if(l>r) swap(l,r);
        if(op==1) Add(1,l,r,rnd()%V+1);
        if(op==2) Mod(1,l,r,rnd()%V+1);
        if(op==3)
        {
            top=0;GetIt(1,l,r);
            sort(q+1,q+top+1);
            int k=rnd()%(r-l+1)+1;
            for(int i=1;i<=top;++i)
                if(q[i].second>=k) {printf("%lld\n",q[i].first);break;}
                else k-=q[i].second;
        }
        if(op==4)
        {
            top=0;GetIt(1,l,r);
            int x=rnd()%V+1,y=rnd()%V+1,ans=0;
         //   for(int i=1;i<=top;++i) printf("%lld %d\n",q[i].first,q[i].second);
            for(int i=1;i<=top;++i) ans=(ans+1LL*q[i].second*pow(q[i].first%y,x,y))%y;
            printf("%d\n",ans);
        }
    }
    return 0;
}