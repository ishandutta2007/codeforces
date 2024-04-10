#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int p[2005], sz[2005];

int find(int u){
    return (p[u] == u)?u:(p[u] = find(p[u]));
}

void combine(int u, int v){
    u = find(u); v = find(v);
    if(u == v)return;
    if(sz[u] < sz[v])swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
}

vector<int> g[2005];
vector<pair<int,int> > eq, nq;
map<int,int> hsh;
int id[2005], od[2005];
int vr[1005], vc[1005];
char arr[1005][1005];

bool check(int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] == '=' && vr[i] != vc[j])return false;
            if(arr[i][j] == '>' && vr[i] <= vc[j])return false;
            if(arr[i][j] == '<' && vr[i] >= vc[j])return false;
        }
    }
    return true;
}

int vis[2005], dist[2005];

int dfs(int v){
    if(vis[v])return dist[v];
    vis[v] = 1;
    int ans = 1;
    for(auto u : g[v]){
        ans = max(ans, 1 + dfs(u));
    }
    return dist[v] = ans;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == '>')nq.push_back({i, n + j});
            else if(arr[i][j] == '<')nq.push_back({n + j, i});
            else eq.push_back({i, n + j});
        }
    }
    for(int i = 1; i <= n + m; i++){
        p[i] = i;
        sz[i] = i;
    }
    for(auto x : eq){
        combine(x.first, x.second);
    }
    if(nq.empty()){
        cout<<"YES"<<endl;
        for(int i = 1; i <= n; i++){
            cout<<1<<" ";
        }
        cout<<endl;
        for(int j = 1; j <= m; j++){
            cout<<1<<" ";
        }
        cout<<endl;
        return 0;
    }
    int ptr = 0;
    memset(id, 0, sizeof(id));
    memset(od, 0, sizeof(od));
    for(auto x : nq){
        if(find(x.first) == find(x.second)){
            cout<<"NO"<<endl;
            exit(0);
        }
        int u = find(x.first), v = find(x.second);
        if(hsh.find(u) == hsh.end()){
            hsh[u] = ++ptr;
        }
        if(hsh.find(v) == hsh.end()){
            hsh[v] = ++ptr;
        }
        od[hsh[u]]++;
        id[hsh[v]]++;
        g[hsh[u]].push_back(hsh[v]);
    }
    vector<int> snk, src;
    for(int i = 1; i <= ptr; i++){
        if(id[i] == 0)src.push_back(i);
        if(od[i] == 0)snk.push_back(i);
    }
    if(src.empty() || snk.empty()){
        cout<<"NO"<<endl;
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    for(auto x : snk){
        dist[x] = 1;
        vis[x] = 1;
    }
    for(auto x : src){
        dfs(x);
    }
    for(int i = 1; i <= n; i++){
        vr[i] = dist[hsh[find(i)]];
    }
    for(int i = 1; i <= m; i++){
        vc[i] = dist[hsh[find(n + i)]];
    }
    if(!check(n, m)){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i = 1; i <= n; i++){
            cout<<vr[i]<<" ";
        }
        cout<<endl;
        for(int i = 1; i <= m; i++){
            cout<<vc[i]<<" ";
        }
    }
}