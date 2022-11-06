#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],rcnt;
void add(int u,int v)
{
    nxt[++rcnt]=head[u];
    to[rcnt]=v;
    head[u]=rcnt;
}
int id[N],tot,nid[N],siz[N];
void dfs(int u,int p)
{
    id[nid[u]=++tot]=u;siz[u]=1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs(v,u);siz[u]+=siz[v];
    }
}
int bl[N];
struct ques{
    int l,r,k,id;
    bool operator <(const ques a)const{return bl[l]==bl[a.l]?r<a.r:bl[l]<bl[a.l];}
}q[N];
#define B 433
#define BL (2*N/B)
struct block{
    int val[BL+3][B+3],sum[BL];
    void add(int x,int v)
    {
        int p=x/B;x=x%B;
        val[p][x]+=v;sum[p]+=v;
    }
    int answer(int k)
    {
        int p=k/B,ans=0;k=k%B;
        for(int i=BL;i>p;i--) ans+=sum[i];
        for(;k<B;k++) ans+=val[p][k];
        return ans;
    }
}res;
int cnt[N],w[N],ans[N];
void add(int u){res.add(cnt[w[id[u]]],-1); cnt[w[id[u]]]++; res.add(cnt[w[id[u]]],1);}
void del(int u){res.add(cnt[w[id[u]]],-1); cnt[w[id[u]]]--; res.add(cnt[w[id[u]]],1);}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++)
    {
        int u;
        scanf("%d%d",&u,&q[i].k);
        q[i].l=nid[u],q[i].r=nid[u]+siz[u]-1;
        q[i].id=i;
    }
    for(int i=1;i<=n;i++) bl[i]=i/B;
    sort(q+1,q+m+1);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        while(l<q[i].l) del(l++);
        while(l>q[i].l) add(--l);
        while(r>q[i].r) del(r--);
        while(r<q[i].r) add(++r);
        ans[q[i].id]=res.answer(q[i].k);
    }
    for(int i=1;i<=m;i++)
    printf("%d\n",ans[i]);
    return 0;
}