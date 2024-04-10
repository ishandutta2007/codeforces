#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int K = 505;
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

int v[K / 2][K];
int h[K / 2][K];
int dist[K * K];
vector<pii> adj[K * K];

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        auto idx = [&](pii x) -> int {
            return x.fi * (k + 1) + x.se;
        };
        memset(v, 0, sizeof(v));
        memset(h, 0, sizeof(h));
        memset(dist, 0, sizeof(dist));
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= k; j++) {
                adj[idx({i, j})].clear();
            }
        }
        vector<pair<pii, pii>> a(n);
        for(auto& [x, y]: a) cin >> x.fi >> x.se >> y.fi >> y.se;
        for(auto& [x, y]: a) {
            if(x > y) swap(x, y);
            if(x.fi > k / 2) {
                x.fi = k + 1 - x.fi;
                x.se = k + 1 - x.se;
                y.fi = k + 1 - y.fi;
                y.se = k + 1 - y.se;
                if(x > y) swap(x, y);
            }
            if(x.fi == y.fi) h[x.fi - 1][x.se - 1]++;
            else v[x.fi - 1][x.se - 1]++;
        }
        auto path = [&](pii x, pii y) -> int {
            //cout << "Path " << x.fi << ' ' << x.se << ' ' << y.fi << ' ' << y.se << endl;
            if(x.fi > k / 2) {
                x.fi = k - x.fi;
                x.se = k - x.se;
            }
            if(y.fi > k / 2) {
                y.fi = k - y.fi;
                y.se = k - y.se;
            }
            if(x > y) swap(x, y);
            //cout << "Proc " << x.fi << ' ' << x.se << ' ' << y.fi << ' ' << y.se << endl;
            if(x.fi < y.fi) return h[x.fi][x.se - 1];
            else return v[x.fi - 1][x.se] + (x.fi == k / 2 ? v[x.fi - 1][k - 1 - x.se] : 0);
        };
        /*cout << "horizontal:\n";
        rep(i, k / 2) rep(j, k) cout << h[i][j] << " \n"[j + 1 == k];
        cout << "vertical:\n";
        rep(i, k / 2) rep(j, k) cout << v[i][j] << " \n"[j + 1 == k];*/
        for(int i = 1; i < k; i++) {
            for(int j = 1; j < k; j++) {
                dist[idx({i, j})] = 1e9;
                rep(l, 4) {
                    int x = i + dx[l];
                    int y = j + dy[l];
                    pii u = {x, y}, v = {i, j};
                    int w = path(u, v);
                    //cout << x << ' ' << y << ' ' << i << ' ' << j << ' ' << w << endl;
                    adj[idx(u)].eb(idx(v), w);
                }
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(int i = 1; i < k; i++) {
            q.emplace(0, idx({0, i}));
            q.emplace(0, idx({k, i}));
            q.emplace(0, idx({i, 0}));
            q.emplace(0, idx({i, k}));
        }
        while(!q.empty()) {
            auto [chk, u] = q.top(); q.pop();
            if(chk != dist[u]) continue;
            for(auto& [v, w]: adj[u]) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.emplace(dist[v], v);
                }
            }
        }
        /*cout << "DP\n";
        for(int i = 0; i <= k; i++) {
            for(int j = 0; j <= k; j++) {
                cout << dist[idx({i, j})] << " ";
            }
            cout << endl;
        }*/
        cout << n - dist[idx({k / 2, k / 2})] << endl;
    }
}