#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 200010
#define C 26
#define ll long long
using namespace std;
char s[N];
struct SAM{
    int ch[N][C],fa[N],len[N],las=1,cnt=1;
    int pos[N];
    int insert(int c)
    {
        int p=las,q=las=++cnt;len[q]=len[p]+1;
        for(;p && !ch[p][c];p=fa[p]) ch[p][c]=q;
        if(!p) fa[q]=1;
        else
        {
            int np=ch[p][c];
            if(len[np]==len[p]+1) fa[q]=np;
            else
            {
                int nq=++cnt;
                fa[nq]=fa[np];len[nq]=len[p]+1;
                fa[np]=fa[q]=nq;
                memcpy(ch[nq],ch[np],sizeof(ch[nq]));
                for(;p && ch[p][c]==np;p=fa[p]) ch[p][c]=nq;
            }
        }
        return q;
    }
    ll init(char s[],int n)
    {
        for(int i=1;i<=n;i++) pos[i]=insert(s[i]-'a');
        ll ans=0;
        for(int i=2;i<=cnt;i++) ans+=len[i]-len[fa[i]];
        return ans;
    }
}t1,t2;
int nxt[N<<1],to[N<<1],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;head[u]=cnt;
}
namespace ST{
    int f[21][N*2],dep[N*2],id[N*2],tot;
    int nid[N*2];
    int _2[N*2];
    void dfs(int u,int p)
    {
        dep[u]=dep[p]+1;
        f[0][++tot]=u;
        id[u]=tot;nid[tot]=u;
        for(int i=head[u];i;i=nxt[i])
        {
            int v=to[i];
            if(v==p) continue;
            dfs(v,u);
            f[0][++tot]=u;nid[tot]=u;
        }
    }
    int lca(int x,int y)
    {
        // x=id[x],y=id[y];
        if(x>y) swap(x,y);
        int p=_2[y-x+1],u=1<<p;
        return dep[f[p][x]]>dep[f[p][y-u+1]]?f[p][y-u+1]:f[p][x];
    }
    void init()
    {
        dfs(1,0);
        for(int i=2;i<=tot;i++) _2[i]=_2[i>>1]+1;
        for(int i=1,p=2;p<=tot;i++,p<<=1)
            for(int j=1;j+p-1<=tot;j++)
            if(dep[f[i-1][j]]<dep[f[i-1][j+p/2]]) f[i][j]=f[i-1][j];
            else f[i][j]=f[i-1][j+p/2];
    }
}
ll ans=0;
using ST::lca;
using ST::id;
using ST::nid;
using ST::tot;
vector<int>g[N];
void init()
{
    for(int i=2;i<=t2.cnt;i++) add(t2.fa[i],i);
    for(int i=2;i<=t1.cnt;i++) g[t1.fa[i]].push_back(i);
    ST::init();
}
int ls[N<<4],rs[N<<4],root[N<<2],fl[N<<4],fr[N<<4],sc;
ll f[N<<4];
int merge(int x,int y)
{
    if(!x || !y) return x+y;
    ls[x]=merge(ls[x],ls[y]);rs[x]=merge(rs[x],rs[y]);
    f[x]=f[ls[x]]+f[rs[x]]-t2.len[lca(fr[ls[x]],fl[rs[x]])];
    fl[x]=fl[ls[x]]?fl[ls[x]]:fl[rs[x]];
    fr[x]=fr[rs[x]]?fr[rs[x]]:fr[ls[x]];
    return x;
}
void upd(int &u,int l,int r,int p)
{
    f[u=++sc]=t2.len[nid[p]];fl[u]=fr[u]=p;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(p<=mid) upd(ls[u],l,mid,p);
    else upd(rs[u],mid+1,r,p);
}
ll val[N];
void solve(int u)
{
    for(int v:g[u]) solve(v),root[u]=merge(root[u],root[v]);
    val[u]=f[root[u]];
}
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    ans+=t1.init(s,n-1);
    t1.pos[n]=t1.insert(s[n]-'a');
    for(int i=2;i<=t1.cnt;i++) ans+=t1.len[i]-t1.len[t1.fa[i]];
    for(int i=n;i>=2;i--) t2.pos[i]=t2.insert(s[i]-'a');
    for(int i=2;i<=t2.cnt;i++) ans+=t2.len[i]-t2.len[t2.fa[i]];
    t2.pos[1]=t2.insert(s[1]-'a');
    ans+=2;
    init();
    // printf("%lld\n",ans);
    // for(int i=1;i<=n;i++) printf("%d ",t1.pos[i]);puts("");
    // for(int i=1;i<=n-2;i++) printf("%d ",t2.pos[i+2]);puts("");
    for(int i=1;i<=n-2;i++) upd(root[t1.pos[i]],1,tot,id[t2.pos[i+2]]);
    solve(1);
    for(int i=2;i<=t1.cnt;i++) ans+=1ll*(t1.len[i]-t1.len[t1.fa[i]])*val[i];
    printf("%lld\n",ans);
    return 0;
}