#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
using  namespace std;
#define maxn 1000000
#define inf 0x7fffffff
using namespace std;
int s,t;
int sum,ans;
int d[maxn];
struct edge{
    int to,val,rev; //revtovector
    edge (int _to,int _val,int _rev) //
    {
        to=_to;
        val=_val;
        rev=_rev;
    }
};
vector<edge> e[maxn];
void addedge(int x,int y,int w)
{
    e[x].push_back(edge(y,w,e[y].size()));
    e[y].push_back(edge(x,0,e[x].size()-1));
    /*
      
     e[x].push_back((edge){y,w,e[y].size()});
     e[y].push_back((edge){x,0,e[x].size()-1});
    ?
     */
}
bool bfs()
{
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<e[x].size();i++)
        {
            int y=e[x][i].to;
            if(d[y]==-1 && e[x][i].val)
            {
                q.push(y);
                d[y]=d[x]+1;
            }
        }
    }
    if(d[t]==-1)
        return 0;
    else
        return 1;
}
int dfs(int x,int low) //xlowx
{
    if(x==t || low==0)
        return low;
    int totflow=0; //totflowx
    for(int i=0;i<e[x].size();i++)
    {
        int y=e[x][i].to;
        int rev=e[x][i].rev;
        if(d[y]==d[x]+1 && e[x][i].val) //yx  >0
        {
            int a=dfs(y,min(low,e[x][i].val)); //a
            e[x][i].val-=a;
            e[y][rev].val+=a;
            low-=a;
            totflow+=a;
            if(low==0) //x
                return totflow;
        }
    }
    if(low!=0) //xdfsx
        d[x]=-1;
    return totflow;
}
void dinic()
{
    while(bfs())
        ans+=dfs(s,inf);
}
const int N = 1e6 + 1;
const int S = 16;
int n, m;
int fa[N][S + 1], deep[N];
vector<pair<int, int> >g[N];
int ide[N];
void dfs(int x) {
    deep[x] ++;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u.first != fa[x][0]) {
            fa[u.first][0] = x;
            ide[u.first] = u.second;
            deep[u.first] = deep[x];
            dfs(u.first);
        }
}
vector<pair<int, int> > dd;
int getlca(int x, int y) {
    int i = S;
    if (deep[x] < deep[y]) swap(x, y);
    while (deep[x] != deep[y]) {
        while (deep[fa[x][i]] < deep[y]) i --;
        dd.push_back(make_pair(x, i));
        x = fa[x][i];
    }
    i = S;
    while (x != y) {
        while (i && fa[x][i] == fa[y][i]) i --;
        dd.push_back(make_pair(x, i));
        dd.push_back(make_pair(y, i));
        x = fa[x][i], y = fa[y][i];
    }
    return x;
}
int id(int x, int y) {
    return m + (x - 1) * (S + 1) + y + 1;
}
vector<int>anse;
vector<int>ansv;
bool bz[N];
void walk(int x) {
    if (bz[x]) return;
    bz[x] = 1;
    for (auto u:e[x])
        if (u.val)
            walk(u.to);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(make_pair(y, i));
        g[y].push_back(make_pair(x, i));
    }
    dfs(1);
    s = 0, t = (S+ 1) * n + m + 1;
    for (int i = 1; i <= n ; addedge(id(i, 0), t, 1),i ++)
        for (int j = 1; j <= S; j ++) {
            addedge(id(i, j), id(i, j - 1), 1e9);
            if (fa[i][j - 1])
                addedge(id(i, j), id(fa[i][j - 1], j - 1), 1e9);
        }
    for (int i = 1; i <= m; i ++)
    {
        int x, y;
        scanf("%d %d", &x ,&y);
        dd.clear();
        getlca(x, y);
        for (auto u:dd)
            addedge(i, id(u.first, u.second), 1);
        addedge(s, i, 1);
    }
    dinic();
    walk(s);
    for (auto u:e[s])
        if (!bz[u.to]) {
            ansv.push_back(u.to);
        }

    for (auto u:e[t])
        if (bz[u.to]) {
            anse.push_back(ide[(u.to - m) / (S + 1) + 1]);
        }
    printf("%d\n", anse.size() + ansv.size());
    printf("%d", ansv.size());
    for (auto u:ansv)
        printf(" %d", u);
    printf("\n");
    printf("%d", anse.size());
    for (auto u:anse)
        printf(" %d", u);
    printf("\n");
    return 0;
}