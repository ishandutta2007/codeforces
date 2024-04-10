#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

int t, n, m, k, a[100010], b[100010];

const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
const ll SEED = (ll)(new ll);
const ll RANDOM = TIME ^ SEED;
const ll MOD = (int)1e9+7;
const ll MUL = (int)1e6+3;

struct chash{
    ll operator()(ll x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }
};

vector<gp_hash_table<int, null_type, chash>> adj(n);
set<pair<int, int>> deg;

vector<int> solve(int k) { /// at least degree k
    deg.clear();
    adj = vector<gp_hash_table<int, null_type, chash>>(n);
    for(int i = 0; i < m; i++) {
        adj[a[i]].insert(b[i]);
        adj[b[i]].insert(a[i]);
    }

    for(int i = 0; i < n; i++)
        deg.insert({adj[i].size(), i});

    while(!deg.empty()) {
        int id = deg.begin()->second;
        if(adj[id].size() >= k) break;
        deg.erase(deg.begin());
        for(int v : adj[id]) {
            deg.erase({adj[v].size(), v});
            adj[v].erase(id);
            deg.insert({adj[v].size(), v});
        }
    }

    vector<int> ret;
    for(auto tt : deg) ret.push_back(tt.second);
    return ret;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a[i], &b[i]);
            a[i]--; b[i]--;
        }

        auto retk = solve(k);
        if(!retk.empty()) {
            printf("1 %d\n", retk.size());
            for(int x : retk) printf("%d ", x + 1);
            puts("");
        } else {
            retk = solve(k-1);
            if(!retk.empty()) {
                int ff = 0;
                for(int i = 0; i < retk.size(); i++) {
                    int v = retk[i];
                    if(adj[v].size() != k-1) continue;
                    vector<int> cliq(adj[v].begin(), adj[v].end());

                    int flag = 1;
                    for(int i = 0; flag && i < cliq.size(); i++)
                        for(int j = i+1; flag && j < cliq.size(); j++)
                            if(adj[cliq[i]].find(cliq[j]) == adj[cliq[i]].end())
                                flag = 0;

                    if(!flag) {
                        function<void(int)> rem = [&](int v){
                            while(!adj[v].empty()) {
                                int u = *adj[v].begin();
                                adj[v].erase(u);
                                adj[u].erase(v);
                                if(adj[u].size() == k-1) retk.push_back(u);
                                if(adj[u].size() < k-1) rem(u);
                            }
                        };
                        rem(v);
                    } else {
                        cliq.push_back(v);
                        printf("2\n");
                        for(int x : cliq) printf("%d ", x + 1);
                        puts("");
                        goto nxt;
                    }
                }
            }
            puts("-1");
        }
        nxt:;
    }
    return 0;
}