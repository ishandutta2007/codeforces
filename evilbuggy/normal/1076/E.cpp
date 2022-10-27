#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

ll f[300005];
int n;

void update(int i, ll x){
    while(i <= n){
        f[i] += x;
        i += i&(-i);
    }
}

ll query(int i){
    ll ans = 0;
    while(i > 0){
        ans += f[i];
        i &= (i-1);
    }
    return ans;
}

int dep[300005];
vector<pair<int,int> > qarr[300005];
vector<int> g[300005];
ll ans[300005];

void dfs(int v, int p){
    dep[v] = dep[p] + 1;
    for(int i = 0; i < qarr[v].size(); i++){
        int x = qarr[v][i].second;
        int d = qarr[v][i].first;
        update(dep[v], x);
        update(dep[v] + d + 1, -x);
    }
    ans[v] = query(dep[v]);
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(u != p){
            dfs(u, v);
        }
    }
    for(int i = 0; i < qarr[v].size(); i++){
        int x = qarr[v][i].second;
        int d = qarr[v][i].first;
        update(dep[v], -x);
        update(dep[v] + d + 1, x);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    int u, v;
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int m, d, x;
    cin>>m;
    while(m--){
        cin>>v>>d>>x;
        qarr[v].push_back(make_pair(d,x));
    }
    memset(ans, 0, sizeof(ans));

    dep[0] = 0;
    dfs(1,0);
    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" ";
    }

}