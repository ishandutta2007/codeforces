#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 1000010
using namespace std;
int nxt[N<<2],to[N<<2],head[N],ed[N],cnt;
void add(int u,int v)
{
    nxt[ed[u]]=++cnt;
    to[ed[u]]=v;
    ed[u]=cnt;
}
struct road{
    int u,v,l,r;
    bool operator <(const road a)const{return l==a.l?r>a.r:l<a.l;}
}rd[N<<1];
int tr[N],tl[N],tot;
queue<int>q;
void add(int u,int v,int l,int r){rd[++tot].u=u,rd[tot].v=v,rd[tot].l=l+((l^u)&1),rd[tot].r=r-((r^v)&1);}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n==1){puts("0");return 0;}
    for(int i=1;i<=m;i++)
    {
        int u,v,l,r;
        scanf("%d%d%d%d",&u,&v,&l,&r);
        add(u<<1,v<<1|1,l,r),add(u<<1|1,v<<1,l,r),add(v<<1,u<<1|1,l,r),add(v<<1|1,u<<1,l,r);
    }
    sort(rd+1,rd+tot+1);
    int ans=1e9;
    for(int i=1;i<=n*2;i++) head[i]=ed[i]=i;cnt=n*2;
    memset(tr,0xc0,sizeof(tr));memset(tl,0xc0,sizeof(tl));
    tl[2]=tr[2]=0;
    for(int i=1;i<=tot;i++)
    {
        int x=rd[i].u,y=rd[i].v,l=rd[i].l=max(rd[i].l,tl[x]),r=rd[i].r;
        if(tr[x]<l){add(x,i);continue;}
        q.push(i);
        while(!q.empty())
        {
            int rm=q.front();q.pop();
            int x=rd[rm].u,y=rd[rm].v,l=rd[rm].l,r=rd[rm].r;
            if(l>=r) continue;
            if(tr[y]+2<l) tl[y]=l+1,tr[y]=r;
            else tr[y]=max(tr[y],r);
            if(y/2==n) ans=min(ans,tl[y]);
            for(int &p=head[y];p!=ed[y];p=nxt[p])
            {
                int v=to[p];
                if(tr[y]>=rd[v].l) q.push(v),rd[v].l=tl[y];
                else break;
            }
        }
    }
    printf("%d\n",ans>=1e9?-1:ans);
    return 0;
}