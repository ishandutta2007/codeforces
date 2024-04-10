#include<bits/stdc++.h>

using namespace std;

const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> g[N];
int par[N],sub[N],level[N],ans[N];
int DP[LOGN][N];
int dt[N];
int n,m;
vector<int> all[110000];
vector<int> smallest[110000][20];

void mergev(vector<int>& v, vector<int>& v2) {
    for (int k : v2) {
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    int k = unique(v.begin(), v.end()) - v.begin();
    v.resize(min(k, 10));
}

/*-----------------Decomposition Part--------------------------*/
int nn;
void dfs1(int u,int p)
{
    sub[u]=1;
    nn++;
    for(auto it=g[u].begin();it!=g[u].end();it++)
        if(*it!=p)
        {
            dfs1(*it,u);
            sub[u]+=sub[*it];
        }
}
int dfs2(int u,int p)
{
    for(auto it=g[u].begin();it!=g[u].end();it++)
        if(*it!=p && sub[*it]>nn/2)
            return dfs2(*it,u);
    return u;
}
void dfs4(int u, int p, vector<int> v, int d) {
    mergev(v, all[u]);
    smallest[u][d] = v;
    for (int k : g[u]) if (k != p) {
        dfs4(k, u, v, d);
    }
}
void decompose(int root,int p, int d)
{
    nn=0;
    dfs1(root,root);
    int centroid = dfs2(root,root);
    if(p==-1)p=centroid;
    par[centroid]=p;
    dt[centroid]=d;
    dfs4(centroid,centroid, vector<int>(), d);
    for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
    {
        g[*it].erase(centroid);
        decompose(*it,centroid,d+1);
    }
    g[centroid].clear();
}
/*----------------- Handle the Queries -----------------*/


void query(int u, int v, int k)
{
    int x = u, y = v;
    while(x != y)
    {
        if (dt[x] < dt[y]) y = par[y];
        else x = par[x];
    }
    vector<int> ans;
    mergev(ans, smallest[u][dt[x]]);
    mergev(ans, smallest[v][dt[x]]);
    int count = min(k, (int)ans.size());
    printf("%d ", count);
    for (int i = 0; i < count; i++) printf("%d ", ans[i]+1);
    printf("\n");
}
int main()
{
    int q;
    scanf("%d %d %d",&n,&m, &q);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u-1].insert(v-1);
        g[v-1].insert(u-1);
    }
    
    for(int i=0;i<m;i++) {
        int loc;
        scanf("%d", &loc); loc--;
        all[loc].push_back(i);
    }
    decompose(0,-1,0);
    while(q--)
    {
        int t,v,k;
        scanf("%d %d %d",&t,&v,&k);t--;v--;
        query(t, v, k);
    }
    return 0;
}