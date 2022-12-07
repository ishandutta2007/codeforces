#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ask[500005],u[500005],v[500005];
vector<pair<int,int> > vec[500005];// vector<pair<to,color>>

//BFS
queue<int> Q;
bool vis[500005];
int bfs(int x)
{
    memset(vis,false,sizeof(vis));
    Q.push(x);
    vis[x]=true;
    int now=-1;
    while(!Q.empty())
    {
        now=Q.front();
        Q.pop();
        for(int i=0;i<vec[now].size();i++)
        {
            if(!vis[vec[now][i].first]) 
            {
                vis[vec[now][i].first]=true;
                Q.push(vec[now][i].first);
            }
        }
    }
    return now;
}

//DFS
int fa[500005],inx[500005],outx[500005],dfn[500005],color[500005],dep[500005],cnt;
void init(int x)
{
    cnt=0;
    color[x]=0;
    dep[0]=-1;
}
void dfs(int x,int y)
{
    fa[x]=y;
    dep[x]=dep[y]+1;
    dfn[++cnt]=x;
    inx[x]=cnt;
    for(int i=0;i<vec[x].size();i++)
    {
        if(vec[x][i].first==y) continue;
        color[vec[x][i].first]=color[x]^vec[x][i].second;
        dfs(vec[x][i].first,x);
    }
    outx[x]=cnt;
    // printf("dep[%d]=%d,inx[%d]=%d,outx[%d]=%d,color[%d]=%d\n",x,dep[x],x,inx[x],x,outx[x],x,color[x]);
}

//Segment Tree
int f[2][2000005]/*0:even 1:odd*/,tag[2000005];
void update(int k)
{
    f[0][k]=max(f[0][2*k],f[0][2*k+1]);
    f[1][k]=max(f[1][2*k],f[1][2*k+1]);
}
void pushdown(int k)
{
    if(tag[k]==0) return;
    tag[2*k]^=1; 
    tag[2*k+1]^=1;
    swap(f[0][2*k],f[1][2*k]);
    swap(f[0][2*k+1],f[1][2*k+1]);
    update(k);
    tag[k]=0;
}
void build(int k,int l,int r)
{
    if(l==r)
    {
        f[color[dfn[l]]][k]=dep[dfn[l]];
        f[color[dfn[l]]^1][k]=-1e7;
        tag[k]=0;
        return;
    }
    int mid=(l+r)/2;
    build(2*k,l,mid);
    build(2*k+1,mid+1,r);
    update(k);
}
void modify(int k,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql) 
        return;
    if(ql<=l && qr>=r)
    {
        // printf("Added %d %d %d\n",k,l,r);
        tag[k]^=1;
        swap(f[0][k],f[1][k]);
        return;
    }
    pushdown(k);
    int mid=(l+r)/2;
    modify(2*k,l,mid,ql,qr);
    modify(2*k+1,mid+1,r,ql,qr);
    update(k);
}
void print(int k,int l,int r)
{
    printf("k=%d,l=%d,r=%d,tag=%d,f[0]=%d,f[1]=%d\n",k,l,r,tag[k],f[0][k],f[1][k]);
    if(l==r) return;
    int mid=(l+r)/2;
    print(2*k,l,mid);
    print(2*k+1,mid+1,r);
}

//WORK
int ans1[500005],ans2[500005];
void work()
{
    int root1=bfs(1);
    int root2=bfs(root1);
    // printf("--root1=%d,root2=%d\n",root1,root2);
    init(root1);
    dfs(root1,0);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        if(fa[u[ask[i]]]==v[ask[i]]) modify(1,1,n,inx[u[ask[i]]],outx[u[ask[i]]]);
        if(fa[v[ask[i]]]==u[ask[i]]) modify(1,1,n,inx[v[ask[i]]],outx[v[ask[i]]]);
        ans1[i]=f[0][1];
        // printf("--------------------------------\n");
        // printf("Print Tree:\n");
        // print(1,1,n);
        // printf("--------------------------------\n");
        // printf("-ans1[%d]=%d\n",i,ans1[i]);
    }
    init(root2);
    dfs(root2,0);
    memset(f,0,sizeof(f));
    memset(tag,0,sizeof(tag));
    build(1,1,n);   
    for(int i=1;i<=m;i++)
    {
        if(fa[u[ask[i]]]==v[ask[i]]) modify(1,1,n,inx[u[ask[i]]],outx[u[ask[i]]]);
        if(fa[v[ask[i]]]==u[ask[i]]) modify(1,1,n,inx[v[ask[i]]],outx[v[ask[i]]]);
        ans2[i]=f[0][1];
        // printf("--------------------------------\n");
        // printf("Print Tree:\n");
        // print(1,1,n);
        // printf("--------------------------------\n");
        // printf("-ans2[%d]=%d\n",i,ans2[i]);
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",max(ans1[i],ans2[i]));
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int tmp;
        scanf("%d%d%d",&u[i],&v[i],&tmp);
        vec[u[i]].push_back(make_pair(v[i],tmp));
        vec[v[i]].push_back(make_pair(u[i],tmp));
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&ask[i]);
    }
    work();
}