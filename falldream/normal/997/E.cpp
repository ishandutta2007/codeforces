#include<bits/stdc++.h>
#define MN 120000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll Ans[MN+5];
int n,m,a[MN+5],b[MN+5],q[MN+5],top,Q[MN+5],Top,cnt;
struct Tree{int l,r,mn,num,val,Val;ll ans;}T[MN*4+5];
vector<pair<int,int> >v[MN+5];
inline void update(int x)
{
    T[x].mn=min(T[x<<1].mn,T[x<<1|1].mn);
    T[x].num=(T[x<<1].mn==T[x].mn?T[x<<1].num:0)+(T[x<<1|1].mn==T[x].mn?T[x<<1|1].num:0);
    T[x].ans=T[x<<1].ans+T[x<<1|1].ans;
}
inline void Mark(int x,int v){T[x].mn+=v;T[x].val+=v;}
inline void Set(int x,int v){T[x].Val+=v;T[x].ans+=1LL*T[x].num*v;}
inline void pushdown(int x)
{
    if(T[x].val) Mark(x<<1,T[x].val),Mark(x<<1|1,T[x].val),T[x].val=0;
    if(T[x].Val) 
    {
        if(T[x<<1].mn==T[x].mn) Set(x<<1,T[x].Val);
        if(T[x<<1|1].mn==T[x].mn) Set(x<<1|1,T[x].Val);
        T[x].Val=0;
    }
}
void Modify(int x,int l,int r,int v)
{
    if(T[x].l==l&&T[x].r==r) return Mark(x,v);
    int mid=T[x].l+T[x].r>>1;pushdown(x);
    if(r<=mid) Modify(x<<1,l,r,v);
    else if(l>mid) Modify(x<<1|1,l,r,v);
    else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
    update(x);
}
ll Query(int x,int l,int r)
{
    if(T[x].l==l&&T[x].r==r) return T[x].ans;
    int mid=T[x].l+T[x].r>>1;pushdown(x);
    if(r<=mid) return Query(x<<1,l,r);
    else if(l>mid) return Query(x<<1|1,l,r);
    else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r);
}
void Build(int x,int l,int r)
{
    if((T[x].l=l)==(T[x].r=r)){T[x].mn=l;T[x].num=1;return;}
    int mid=l+r>>1;
    Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
    update(x);
}
int main()
{
    n=read();Build(1,1,n);
    for(int i=1;i<=n;++i) a[i]=read();
    m=read();
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        v[r].push_back(make_pair(l,i));
    }
    for(int i=1;i<=n;++i)
    {
        cnt=0;
        while(top&&a[i]<=a[q[top]]) Modify(1,q[top-1]+1,q[top],a[q[top]]),--top;
        Modify(1,q[top]+1,i,-a[i]);q[++top]=i;
        while(Top&&a[i]>=a[Q[Top]]) Modify(1,Q[Top-1]+1,Q[Top],-a[Q[Top]]),--Top;
        Modify(1,Q[Top]+1,i,a[i]);Q[++Top]=i;
        Modify(1,1,n,-1);Set(1,1);
        for(int j=0;j<v[i].size();++j) Ans[v[i][j].second]=Query(1,v[i][j].first,i);
    }
    for(int i=1;i<=m;++i) printf("%lld\n",Ans[i]);
    return 0;
}