#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

template<typename K, typename V>
class hashmap
{
public:
    hashmap() = default;
    V& operator[](const K& k)
    {
        for (uint i = hash(k);; (i += 1) &= (N - 1)) {
            if (not m_used.test(i)) {
                m_keys[i] = k, m_used.set(i);
                return m_vals[i] = V{};
            }
            if (m_keys[i] == k) { return m_vals[i]; }
        }
    }
    void reset()
    {
        m_used.reset();
    }
private:
    static constexpr int LG = 20;
    static constexpr int N = 1 << LG;
    static constexpr ull r = 11995408973635179863ULL;
    static constexpr uint hash(const ull a) { return (a * r) >> (64 - LG); }
    std::bitset<N> m_used;
    K m_keys[N];
    V m_vals[N];
};

constexpr int N = 1e5 + 5;
constexpr int M = 2e5 + 5;
constexpr int T = 250;

vector<pii> edges[M << 1]; //edges with step = i
int dp[N];
int a[N];
bool vis[M << 1];
vi in;

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) cin >> a[i], a[i] += int(1e5);
    auto work = [&](int step) {
        static hashmap<int, int> lst;
        lst.reset();
        for(int i = n - 1; ~i; i--) {
            a[i] -= step * i;
            if(lst[a[i]]) edges[step + M].eb(i, lst[a[i]]);
            lst[a[i]] = i;
            a[i] += step * i;
        }
    };
    work(0);
    rep1(i, T) work(i), work(-i);
    rep(i, n) {
        for(int d = 1; d <= M / T && i + d < n; d++) {
            int j = i + d;
            if((a[j] - a[i]) % d == 0) {
                int step = (a[j] - a[i]) / d;
                if(abs(step) > T && !vis[step + M]) {
                    vis[step + M] = 1;
                    in.pb(step + M);
                    edges[step + M].eb(i, j);
                }
            }
            for(int x: in) vis[x] = 0;
            in.clear();
        }
    }
    int ans = 0;
    for(int step = T + 1; step < M; step++) {
        reverse(all(edges[step + M]));
        reverse(all(edges[-step + M]));
    }
    rep(i, M << 1) if(!edges[i].empty()) {
        for(auto& [u, v]: edges[i]) {
            if(!vis[u]) vis[u] = 1, in.pb(u), dp[u] = 0;
            if(!vis[v]) vis[v] = 1, in.pb(v), dp[v] = 0;
            dp[u] = max(dp[u], dp[v] + 1);
            ans = max(ans, dp[u]);
        }
        for(int x: in) vis[x] = 0;
        in.clear();
    }
    cout << n - ans - 1 << endl;
}