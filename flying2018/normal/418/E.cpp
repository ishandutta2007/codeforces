#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define N 200010
#define M N*40
using namespace std;
int root[N],siz[M],ls[M],rs[M],cnt;
void insert(int &u,int l,int r,int p,int v)
{
    if(!u) u=++cnt;
    if(l==r){siz[u]+=v;return;}
    int mid=(l+r)>>1;
    if(p<=mid) insert(ls[u],l,mid,p,v);
    else insert(rs[u],mid+1,r,p,v);
    siz[u]=siz[ls[u]]+siz[rs[u]];
}
int answer(int u,int l,int r,int p)
{
    if(!u) return 0;
    if(l==r) return siz[u];
    int mid=(l+r)>>1;
    if(p<=mid) return answer(ls[u],l,mid,p);
    else return siz[ls[u]]+answer(rs[u],mid+1,r,p);
}
int answerb(int u,int l,int r,int p)
{
    if(!u) return 0;
    if(l==r) return siz[u];
    int mid=(l+r)>>1;
    if(p>mid) return answerb(rs[u],mid+1,r,p);
    else return siz[rs[u]]+answerb(ls[u],l,mid,p);
}
#define B 800
int bl[N*2];
struct Opt{
    int opt,x,y,id;
}q[N];
struct odpt{
    int t,y;
}qt[N];
bool operator <(const odpt a,const odpt b){return bl[a.y]==bl[b.y]?a.t<b.t:bl[a.y]<bl[b.y];}
int qtot;
int w[N],p[N*2],tto;
int swp[N],ans[N],tot[N];
int tval[N];
int lowbit(int x){return x&(-x);}
void t_insert(int x,int v){for(;x;x-=lowbit(x)) tval[x]+=v;}
int t_answer(int n,int x){int ans=0;for(;x<=n;x+=lowbit(x)) ans+=tval[x];return ans;}
void change(int n,int x,int y)
{
    if(x)
    {
        t_insert(tot[x],-1);
        tot[x]--;
        t_insert(tot[x],1);
    }
    if(y)
    {
        t_insert(tot[y],-1);
        tot[y]++;
        t_insert(tot[y],1);
    }
}
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]),p[++tto]=w[i];
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&q[i].opt,&q[i].x,&q[i].y);
        q[i].id=i;
        if(q[i].opt==1) p[++tto]=q[i].x;
    }
    sort(p+1,p+tto+1);
    tto=unique(p+1,p+tto+1)-p-1;
    for(int i=1;i<=n;i++) w[i]=lower_bound(p+1,p+tto+1,w[i])-p;
    for(int i=1;i<=k;i++)
        if(q[i].opt==1) q[i].x=lower_bound(p+1,p+tto+1,q[i].x)-p;
    for(int i=1;i<=n;i++) insert(root[w[i]],1,n,i,1),swp[i]=w[i];
    for(int i=1;i<=k;i++)
    if((q[i].opt==2 && q[i].x%2==1 && q[i].x!=1))
    {
        ++qtot;
        qt[qtot]=(odpt){i,q[i].y};
    }
    for(int i=1;i<=n;i++) bl[i]=i/B;
    sort(qt+1,qt+qtot+1);
    for(int i=1;i<=k;i++)
    {
        int x=q[i].x,y=q[i].y;
        if(q[i].opt==2)
        {
            if(x==1){ans[i]=p[w[y]];continue;}
            if(x%2==0) ans[i]=answer(root[w[y]],1,n,y);
        }
        else
        {
            q[i].id=w[y];
            insert(root[w[y]],1,n,y,-1);
            w[y]=x;
            insert(root[w[y]],1,n,y,1);
        }
    }
    int r=0,t=0;
    for(int i=1;i<=n;i++) w[i]=swp[i];
    for(int i=1;i<=qtot;i++)
    {
        while(r<qt[i].y){++r;change(n,0,w[r]);}
        while(r>qt[i].y){change(n,w[r],0);--r;}
        for(;t<qt[i].t;)
        {
            t++;
            if(q[t].opt!=1) continue;
            if(q[t].y<=qt[i].y) change(n,w[q[t].y],q[t].x);
            w[q[t].y]=q[t].x;
        }
        for(;t>qt[i].t;t--)
        {
            if(q[t].opt!=1) continue;
            if(q[t].y<=qt[i].y) change(n,w[q[t].y],q[t].id);
            w[q[t].y]=q[t].id;
        }
        ans[qt[i].t]=t_answer(n,tot[w[qt[i].y]]);
    }
    for(int i=1;i<=k;i++)
    if(q[i].opt==2)printf("%d\n",ans[i]);
    return 0;
}