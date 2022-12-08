#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<"@"<<__LINE__<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    rep(test,0,tests) {
        int n, k;
        cin >> n >> k;
        vector<vector<pair<int,ll>>> g(n);
        rep(i,0,n-1) {
            int u,v,w;
            cin>>u>>v>>w;
            --u;
            --v;
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }
        vector<ll> dp1(n), dp2(n);
        function<void(int,int)> solve = [&](int u, int p) {
            vector<ll> opts;
            ll acc = 0;
            for(auto &e:g[u]) {
                int v = e.first, w = e.second;
                if(v==p) continue;
                solve(v, u);
                acc += dp1[v];
                opts.push_back(max(0LL,dp2[v]+w-dp1[v]));
            }
            sort(all(opts),greater<ll>());
            rep(i,0,k) {
                if(i>=sz(opts)) {
                    dp1[u] = acc;
                    dp2[u] = acc;
                    break;
                }
                if(i==k-1) dp2[u] = acc;
                acc += opts[i];
                if(i==k-1) dp1[u] = acc;
            }
            // debug(u);
            // debug(dp1[u]);
            // debug(dp2[u]);
        };
        solve(0,-1);
        cout<<dp1[0]<<"\n";
    }
}