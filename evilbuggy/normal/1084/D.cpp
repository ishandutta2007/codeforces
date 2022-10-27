#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll w[300005], mx[300005];
vector<pair<int, ll> > g[300005];

ll dfs1(int v, int p){
    ll ans = 0;
    for(auto x : g[v]){
        if(x.first == p)continue;
        ll tmp = dfs1(x.first, v);
        if(tmp + w[x.first] < x.second)continue;
        ans = max(ans, tmp + w[x.first] - x.second);
    }
    mx[v] = ans;
    return ans;
}

ll dfs2(int v, int p, ll maxi){
    ll ans = maxi + w[v];
    ll cost1 = 0, cost2 = 0;
    for(auto x : g[v]){
        if(x.first == p)continue;
        if(mx[x.first] + w[x.first] - x.second > cost1){
            cost2 = cost1;
            cost1 = mx[x.first] + w[x.first] - x.second;
        }else if(mx[x.first] + w[x.first] - x.second > cost2){
            cost2 = mx[x.first] + w[x.first] - x.second;
        }
    }
    for(auto x : g[v]){
        if(x.first == p)continue;
        ll tcost = 0;
        if(mx[x.first] + w[x.first] - x.second != cost1){
            tcost = max(cost1 + w[v] - x.second, 0LL);
        }else{
            tcost = max(cost2 + w[v] - x.second, 0LL);
        }
        ans = max(ans, dfs2(x.first, v, max(tcost, maxi + w[v] - x.second)));
    }
    return ans;
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

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>w[i];
    }
    int u, v, c;
    for(int i = 1; i < n; i++){
        cin>>u>>v>>c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    dfs1(1, 0);
    cout<<dfs2(1, 0, 0)<<endl;
}