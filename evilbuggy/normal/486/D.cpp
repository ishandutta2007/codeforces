#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1000000007;

vector<int> g[2005], arr[2005];
bool dead[2005];
int d, a[2005], maxima;
ll dp[2005];

void dfs(int v, int p){
    ll ret = 1;
    for(auto u : g[v]){
        if(u == p)continue;
        if(!dead[u] && a[u] >= maxima - d && a[u] <= maxima){
            dfs(u, v);
            (ret *= (1 + dp[u])) %= mod;
        }
    }
    dp[v] = ret;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>d>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        arr[a[i]].push_back(i);
    }
    int u, v;
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 1; i <= 2000; i++){
        if(arr[i].empty())continue;
        maxima = i;
        for(auto x : arr[i]){
            dfs(x, 0);
            (ans += dp[x]) %= mod;
            dead[x] = 1;
        }
        for(auto x : arr[i]){
            dead[x] = 0;
        }
    }
    cout<<ans<<endl;
}