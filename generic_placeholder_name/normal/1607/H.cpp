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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

constexpr int N = 2e5 + 5;
constexpr int M = 2e6 + 6;
int a[N], b[N], m[N];
int aa[N], bb[N];
bool vis[N];
vi occ[M];

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        unordered_set<int> vals;
        rep(i, n) {
            cin >> a[i] >> b[i] >> m[i];
            occ[a[i] + b[i] - m[i]].pb(i);
            vals.insert(a[i] + b[i] - m[i]);
        }
        memset(vis, 0, n * sizeof(bool));
        int ans = 0;
        for(int v: vals) {
            vector<tuple<int, int, int>> events;
            for(int i: occ[v]) {
                events.eb(max(0, a[i] - m[i]), 0, i);
                events.eb(a[i] - max(0, m[i] - b[i]), 1, i);
            }
            sort(all(events));
            queue<int> q;
            for(auto& [v, t, i]: events) {
                if(!t) q.push(i);
                else {
                    if(vis[i]) continue;
                    while(!q.empty()) {
                        int j = q.front();
                        vis[j] = 1;
                        q.pop();
                        aa[j] = a[j] - v;
                        bb[j] = m[j] - aa[j];
                    }
                    ans++;
                }
            }
            occ[v].clear();
        }
        cout << ans << endl;
        rep(i, n) cout << aa[i] << ' ' << bb[i] << endl;
    }
}