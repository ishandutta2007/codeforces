#include<bits/stdc++.h>
using namespace std;
#define MN 200000
#define N 262144
#define ll long long
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
ll f[MN+5],t[N*2+5];
int n,m,Q,from,a[MN+5],b[MN+5];
vector<pair<int,int> > v[MN+5];
struct Tree{int l,r;ll x,val;}T[MN*4+5];
void Build(int x,int l,int r)
{
    if((T[x].l=l)==(T[x].r=r)){T[x].x=b[l];return;}
    int mid=l+r>>1;
    Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
    T[x].x=min(T[x<<1].x,T[x<<1|1].x);
}
inline void Mark(int x,ll v){T[x].x+=v;T[x].val+=v;}
inline void pushdown(int x){Mark(x<<1,T[x].val),Mark(x<<1|1,T[x].val);T[x].val=0;}
void Modify(int x,int l,int r,ll v)
{
    if(T[x].l==l&&T[x].r==r) return Mark(x,v);
    int mid=T[x].l+T[x].r>>1;if(T[x].val) pushdown(x);
    if(r<=mid) Modify(x<<1,l,r,v);
    else if(l>mid) Modify(x<<1|1,l,r,v);
    else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
    T[x].x=min(T[x<<1].x,T[x<<1|1].x);
}
void Renew(int x,ll v){for(t[x+=N]=v;x>>=1;)t[x]=min(t[x<<1],t[x<<1|1]);}
int main()
{
    n=read();m=read();Q=read();
    for(int i=1;i<n;++i) a[i]=read(),b[i+1]=read();Build(1,1,n);
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        v[x].push_back(make_pair(y,w));
    }
    memset(t,127,sizeof(t));
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<v[i].size();++j) Modify(1,1,v[i][j].first,v[i][j].second);
        f[i]=T[1].x;Renew(i,f[i]+a[i]);
    }
    printf("%I64d\n",t[1]);
    for(int i=1;i<=Q;++i)
    {
        int x=read(),w=read();Renew(x,f[x]+w);
        printf("%I64d\n",t[1]);
    }
    return 0;
}