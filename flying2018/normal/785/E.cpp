#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define M N*120
using namespace std;
int val[M],ls[M],rs[M],cnt;
void insert(int &u,int l,int r,int p,int v)
{
    if(!u) u=++cnt;val[u]+=v;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(p<=mid) insert(ls[u],l,mid,p,v);
    else insert(rs[u],mid+1,r,p,v);
    val[u]=val[ls[u]]+val[rs[u]];
}
int answer(int u,int l,int r,int L,int R)
{
    if(R<L || L>r || l>R) return 0;
    if(L<=l && r<=R) return val[u];
    int mid=(l+r)>>1;
    return answer(ls[u],l,mid,L,R)+answer(rs[u],mid+1,r,L,R);
}
int n,root[N];
int add(int x,int y,int v){for(;x<=n;x+=(x&(-x))) insert(root[x],1,n,y,v);}
int answ(int x,int l,int r){int ans=0;for(;x;x-=(x&(-x))) ans+=answer(root[x],1,n,l,r);return ans;}
int qry(int l,int r,int L,int R){return answ(r,L,R)-answ(l-1,L,R);}
int p[N];
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    long long ans=0;
    for(int i=1;i<=n;i++) p[i]=i,add(i,i,1);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l==r){printf("%lld\n",ans);continue;}
        if(l>r)swap(l,r);
        ans+=-qry(l+1,r-1,1,p[l]-1)+qry(l+1,r-1,p[l]+1,n);
        ans+=qry(l+1,r-1,1,p[r]-1)-qry(l+1,r-1,p[r]+1,n);
        ans+=p[l]<p[r]?1:-1;
        printf("%lld\n",ans);
        add(l,p[l],-1),add(r,p[r],-1),add(l,p[r],1),add(r,p[l],1);swap(p[l],p[r]);
    }
    return 0;
}