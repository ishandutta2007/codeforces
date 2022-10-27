#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mx = 1e18;

vector<int> g[100005];
ll a[100005], f[100005];
ll totsum;

void dfs1(int v, int p){
    f[v] = 1;
    int cnt = 0;
    for(auto u : g[v]){
        if(u == p)continue;
        dfs1(u, v);
        cnt++;
        ll tmp = __gcd(f[u], f[v]);
        if(f[u]/tmp > mx/f[v]){
            cout<<totsum<<endl;
            exit(0);
        }
        f[v] = (f[v]*f[u])/tmp;
    }
    if(cnt == 0)return;
    f[v] *= cnt;
}

bool dfs(int v, int p, ll val){
    int cnt = 0;
    for(auto u : g[v]){
        if(u != p)cnt++;
    }
    if(cnt == 0){
        return (val <= a[v]);
    }
    bool tmp = true;
    for(auto u : g[v]){
        if(u != p)tmp &= dfs(u, v, val/cnt);
    }
    return tmp;
}

ll search(ll val){
    ll l = 0, r = totsum/val;
    while(l < r){
        ll m = l + (r - l + 1)/2;
        if(dfs(1, 0, val*m))l = m;
        else r = m - 1;
    }
    return val*l;
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

    int n; cin>>n;
    totsum = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        totsum += a[i];
    }
    int u, v;
    for(int i = 1; i < n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    cout<<totsum - search(f[1])<<endl;

}