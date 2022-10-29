#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stack>
#define NIL -1
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
set<int> a[1000006];
int component;
int cnt = 0;
class Edge {
public:
    int u;
    int v;
    Edge(int u, int v);
};
Edge::Edge(int u, int v){
    this->u = u;
    this->v = v;
}
class Graph{
    int V; // No. of vertices
    int E; // No. of edges
    list<int>* adj; // A dynamic array of adjacency lists
    // A Recursive DFS based function used by BCC()
    void BCCUtil(int u, int disc[], int low[],
       list<Edge>* st, int parent[]);

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BCC(); // prints strongly connected components
};

Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    E++;
}
void Graph::BCCUtil(int u, int disc[], int low[], list<Edge>* st,int parent[])
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    int children = 0;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of 'u'
        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            st->push_back(Edge(u, v));
            BCCUtil(v, disc, low, st, parent);
            low[u] = min(low[u], low[v]);
            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
                component++;
                while (st->back().u != u || st->back().v != v) {
                    a[st->back().u].insert(component);
                    a[component].insert(st->back().u);
                    a[st->back().v].insert(component);
                    a[component].insert(st->back().v);
                    st->pop_back();
                }   
                a[st->back().u].insert(component);
                a[component].insert(st->back().u);
                a[st->back().v].insert(component);
                a[component].insert(st->back().v);
                st->pop_back();
                cnt++;
            }
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
            if (disc[v] < disc[u]) {
                st->push_back(Edge(u, v));
            }
        }
    }
}

void Graph::BCC()
{
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    list<Edge>* st = new list<Edge>[E];
    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        parent[i] = NIL;
    }
    for (int i = 0; i < V; i++) {
        if (disc[i] == NIL)
            BCCUtil(i, disc, low, st, parent);
        int j = 0;
        if(st->size()) component++;
        while (st->size() > 0) {
            j = 1;
            a[st->back().u].insert(component);
            a[component].insert(st->back().u);
            a[st->back().v].insert(component);
            a[component].insert(st->back().v);
            st->pop_back();
        }
        if (j == 1) {
            cnt++;
        }
    }
}
int n,m,q,vis[1000006],height[1000006],dp[20][1000006];
void dfs(int node,int par){
    vis[node]=1;
    dp[0][node]=par;
    height[node]=height[par]+1;
    for(auto i:a[node]){
        if(vis[i]) continue;
        dfs(i,node);
    }
}
void pre(){
    rep(i,1,20){
        rep(j,0,component+1){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
}
int lca(int u,int v){
    if(height[u]>height[v])swap(u,v);
    for(int i=17;i>=0;i--){
        if(height[v]-(1<<i)>=height[u])v=dp[i][v];
    }
    if(u==v)return u;
    for(int i=17;i>=0;i--){
        if(dp[i][u]!=dp[i][v])u=dp[i][u],v=dp[i][v];
    }
    return dp[0][u];
}
void solve(){
    cin>>n>>m>>q;
    component=n;
    Graph G(n);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        G.addEdge(u,v);
        G.addEdge(v,u);
    }
    G.BCC();
    dfs(0,0);
    pre();
    while(q--){
        int u,v;
        cin>>u>>v;
        u--,v--;
        int l=lca(u,v);
        cout<<(height[u]+height[v]-2*height[l])/2<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}