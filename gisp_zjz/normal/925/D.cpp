#include<bits/stdc++.h>
#define maxn 550300

using namespace std;
int dis[maxn],sz[maxn],pre[maxn],ht[maxn],n,m,k,r,pr[maxn],ans[maxn],d[maxn];
int x[maxn],y[maxn],fg;
vector <int> h[maxn];

int ffind(int x)
{
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]);
    return pre[x];
}

void union_(int u,int v)
{
    u=ffind(u);
    v=ffind(v);
    if (u==v) return ;
    if (ht[u]<ht[v]) swap(u,v);
    sz[u]+=sz[v]; pre[v]=u;
    if (ht[u]==ht[v]) ht[u]++;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
        scanf("%d%d",&x[i],&y[i]);
    memset(dis,-1,sizeof(dis));
    for (int i=0;i<m;i++) {
        h[x[i]].push_back(y[i]);
        h[y[i]].push_back(x[i]);
        d[x[i]]++;d[y[i]]++;
    }
    queue <int> q;
    q.push(1); dis[1]=0;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        if (dis[u]==2) fg=u;
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i];
            if (dis[v]!=-1) continue;
            dis[v]=dis[u]+1;
            pr[v]=u;
            q.push(v);
        }
    }
    if (dis[n]!=-1&&dis[n]<=4+(!fg)){
        cout << dis[n] << endl;
        r=0; ans[r]=n; int tmp=n;
        for (int i=1;i<=dis[n];i++) tmp=pr[tmp],ans[i]=tmp;
        for (int i=dis[n];i>=0;i--) printf("%d ",ans[i]); printf("\n"); return 0;
    }
    if (fg){
        cout << 4 << endl;
        cout << 1 << ' ' << pr[fg] << ' ' << fg << ' ' << 1 << ' ' << n << endl;
        return 0;
    }
    for (int i=2;i<=n;i++) pre[i]=i,sz[i]=1;
    for (int i=0;i<m;i++) if (x[i]!=1&&y[i]!=1) union_(x[i],y[i]); r=0;
    for (int i=2;i<=n;i++)
    {
        if (dis[i]==-1) continue;
        if (sz[ffind(i)]>d[i]) r=i;
    }
    if (!r) {cout << -1 << endl; return 0;}
    memset(dis,-1,sizeof(dis));
    q.push(r); dis[r]=0;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        if (dis[u]==2) fg=u;
        for (int i=0;i<h[u].size();i++)
        {
            int v=h[u][i];
            if (v==1) continue;
            if (dis[v]!=-1) continue;
            dis[v]=dis[u]+1;
            pr[v]=u;
            q.push(v);
        }
    }
    cout << 5 << endl;
    cout << 1 << ' ' << r << ' ' << pr[fg] << ' ' << fg << ' ' << r << ' ' << n << endl;
    return 0;
}