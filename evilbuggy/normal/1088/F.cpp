#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[500005], d[500005], p[500005][20];
vector<int> g[500005];
int numOfComp;

void dfs(int v, int par, int dep = 1){
    p[v][0] = par;
    d[v] = dep;
    for(auto u : g[v]){
        if(u != par)dfs(u, v, dep + 1);
    }
}

int dsp[500005], sz[500005];

int find(int v){
    return (dsp[v] == v)?v:(dsp[v] = find(dsp[v]));
}

bool combine(int u, int v){
    u = find(u); v = find(v);
    if(u == v)return false;
    if(sz[v] > sz[u])swap(u, v);
    dsp[v] = u;
    sz[u] += sz[v];
    return true;
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

    int n, rt = 1;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[rt] > a[i])rt = i;
    }
    int u, v;
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(rt, rt);
    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= n; i++){
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    for(int i = 1; i <= n; i++){
        dsp[i] = i; sz[i] = 1;
    }
    ll ans = 0;
    numOfComp = n;
    while(numOfComp > 1){
        vector<pair<ll, pair<int,int> > >arr;
        for(int i = 1; i <= n; i++){
            int ind = -1, mcost = -1;
            for(int j = 0; j < 20; j++){
                if(find(i) == find(p[i][j]))continue;
                ll cost = 1LL*(j+1)*a[p[i][j]] + a[i];
                if(ind == -1 || mcost > cost){
                    ind = p[i][j];
                    mcost = cost;
                }
                if(p[i][j] == rt)break;
            }
            if(ind != -1){
                arr.push_back({mcost, {ind, i}});
            }
        }
        for(auto x : arr){
            if(combine(x.second.first, x.second.second)){
                ans += x.first;
                numOfComp--;
            }
        }
    }
    cout<<ans<<endl;
}