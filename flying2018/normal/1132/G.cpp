#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int st[N],tp;
int a[N],id[N],siz[N],nid;
void dfs(int u,int p=0)
{
    id[u]=++nid;siz[u]=1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(v==p) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int val[N<<2],tag[N<<2];
void push_down(int u)
{
    if(!tag[u]) return;
    tag[u<<1]+=tag[u];tag[u<<1|1]+=tag[u];
    val[u<<1]+=tag[u];val[u<<1|1]+=tag[u];
    tag[u]=0;
}
void insert(int u,int l,int r,int L,int R,int v)
{
    if(L<=l && r<=R){val[u]+=v,tag[u]+=v;return;}
    int mid=(l+r)>>1;
    push_down(u);
    if(L<=mid) insert(u<<1,l,mid,L,R,v);
    if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
    val[u]=max(val[u<<1],val[u<<1|1]);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        while(tp && a[st[tp]]<a[i]) add(i,st[tp]),tp--;
        st[++tp]=i;
    }
    while(tp) add(n+1,st[tp]),tp--;
    dfs(n+1);
    for(int i=1;i<=k;i++) insert(1,1,n+1,id[i],id[i]+siz[i]-1,1);
    printf("%d ",val[1]);
    for(int i=k+1;i<=n;i++)
    {
        insert(1,1,n+1,id[i],id[i]+siz[i]-1,1);
        insert(1,1,n+1,id[i-k],id[i-k]+siz[i-k]-1,-1);
        printf("%d ",val[1]);
    }
    return 0;
}