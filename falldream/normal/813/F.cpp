#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
#define MN 100000
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}
bool Ans[MN+5];
map<long long,int> mp;
int n,q,cnt=1,fa[MN+5],W[MN+5],val[MN+5],size[MN+5],A[MN+5],B[MN+5];
struct Tree{int l,r;vector<pa> x;vector<int> v;}T[MN*4+5];

void Ins(int x,int l,int r,pa v)
{
   // cout<<"INs"<<x<<" "<<l<<" "<<r<<" "<<endl;
    if(T[x].l==l&&T[x].r==r) {T[x].x.push_back(v);return;}
    int mid=T[x].l+T[x].r>>1;
    if(r<=mid) Ins(x<<1,l,r,v);
    else if(l>mid) Ins(x<<1|1,l,r,v);
    else Ins(x<<1,l,mid,v),Ins(x<<1|1,mid+1,r,v);
}

void build(int x,int l,int r)
{
    if((T[x].l=l)==(T[x].r=r))return;
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
}
inline int getfa(int x)
{
    if(fa[x]==x) return x;
    int F=getfa(fa[x]);
    return val[x]=val[fa[x]]^W[x],F;
}
void Solve(int k,bool flag)
{
    //cout<<"Solve"<<k<<" "<<T[k].x.size()<<endl;
    for(int i=0;i<T[k].x.size();++i)
    {
        int x=T[k].x[i].first,y=T[k].x[i].second;
    //    cout<<x<<" "<<y<<endl;fflush(stdout);
        int f1=getfa(x),f2=getfa(y);
    //    cout<<f1<<" "<<f2<<" "<<endl;fflush(stdout);
        if(size[f1]>size[f2]) swap(f1,f2);
        if(f1==f2) flag|=(val[x]==val[y]);
        else
        {
            size[f2]+=size[f1];fa[f1]=f2;
            W[f1]=val[x]==val[y];
            T[k].v.push_back(f1);
        }
    }
   // cout<<"ok"<<endl;fflush(stdout);
    if(T[k].l==T[k].r) Ans[T[k].l]=flag;
    else Solve(k<<1,flag),Solve(k<<1|1,flag);
    for(int i=0;i<T[k].v.size();++i)
    {
        int x=T[k].v[i];fa[x]=x;
        size[fa[x]]-=size[x];W[x]=val[x]=0;
    }
}

int main()
{
    n=read();q=read();build(1,1,q);
    for(int i=1;i<=n;++i) fa[i]=i,size[i]=1,val[i]=W[i]=0;
    for(int i=1;i<=q;++i)
    {
        int x=read(),y=read();
        if(mp[1LL*x*MN+y])
        {
            Ins(1,mp[1LL*x*MN+y],i-1,mp(x,y));
            mp[1LL*x*MN+y]=0;
        }
        else mp[1LL*x*MN+y]=i;
        A[i]=x;B[i]=y;
    }
    for(int i=1;i<=q;++i)
    {
        int x=mp[1LL*A[i]*MN+B[i]];
        if(x) mp[1LL*A[i]*MN+B[i]]=0,Ins(1,x,q,mp(A[i],B[i]));
    }
    Solve(1,0);
    for(int i=1;i<=q;++i) puts(Ans[i]?"NO":"YES");
    return 0;
}