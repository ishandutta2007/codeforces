#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[200001<<1];
int T,n,m,a[200001],h[200001],tot,fa[200001],val[200001],dfn[200001<<1],low[200001<<1],col[200001<<1],cnt;
bool vis[200001<<1];
stack<int> t;
vector<int> v[200001<<1];
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline void dfs(int k,int f,int v)
{
    val[k]=v;
    fa[k]=f;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,e[i].weight);
    }
}
void tarjan(int k)
{
    dfn[k]=++cnt;
    low[k]=cnt;
    vis[k]=1;
    t.push(k);
    int node=k>n? k-n:k;
    if(a[node]==-1)
        a[node]=k>n;
    for(int i:v[k])
    {
        if(!dfn[i])
        {
            tarjan(i);
            low[k]=min(low[k],low[i]);
        }
        else
            if(vis[i])
                low[k]=min(low[k],dfn[i]);
    }
    if(dfn[k]==low[k])
    {
        vis[k]=0;
        col[k]=k;
        while(!t.empty()&&t.top()!=k)
        {
            col[t.top()]=k;
            vis[t.top()]=0;
            t.pop();
        }
        if(!t.empty())
            t.pop();
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n<<1;++i)
            v[i].clear();
        for(int i=1;i<=n<<1;++i)
            vis[i]=col[i]=dfn[i]=low[i]=0;
        for(int i=1;i<=n;++i)
            h[i]=fa[i]=0,a[i]=val[i]=-1;
        tot=cnt=0;
        while(!t.empty())
            t.pop();
        for(int i=1;i<n;++i)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            add(x,y,w);
            add(y,x,w);
            if(w==-1)
                continue;
            w=__builtin_parity(w);
            if(w==0)
            {
                v[x].push_back(y);
                v[y].push_back(x);
                v[x+n].push_back(y+n);
                v[y+n].push_back(x+n);
            }
            if(w==1)
            {
                v[x].push_back(y+n);
                v[y+n].push_back(x);
                v[x+n].push_back(y);
                v[y].push_back(x+n);
            }
        }
        for(int i=1;i<=m;++i)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            if(w==0)
            {
                v[x].push_back(y);
                v[y].push_back(x);
                v[x+n].push_back(y+n);
                v[y+n].push_back(x+n);
            }
            if(w==1)
            {
                v[x].push_back(y+n);
                v[y+n].push_back(x);
                v[x+n].push_back(y);
                v[y].push_back(x+n);
            }
        }
        bool flag=1;
        for(int i=1;i<=n<<1;++i)
            if(!col[i])
                tarjan(i);
        for(int i=1;i<=n;++i)
            if(col[i]==col[i+n])
            {
                puts("NO");
                flag=0;
                break;
            }
        if(!flag)
            continue;
        puts("YES");
        dfs(1,0,-1);
        for(int i=2;i<=n;++i)
            printf("%d %d %d\n",fa[i],i,(val[i]==-1? (a[fa[i]]^a[i]):val[i]));
    }
    return 0;
}