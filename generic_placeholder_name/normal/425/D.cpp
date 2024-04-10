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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>
pref_trie;

template<typename K>
class hashset {
public:
    hashset() = default;
    void insert(const K& k) {
        for(uint i = hash(k);; (i += 1) &= (N - 1)) {
            if (not m_used.test(i)) {
                m_keys[i] = k, m_used.set(i);
                return;
            }
            if (m_keys[i] == k) return;
        }
    }
    bool contains(const K& k) const {
        for(uint i = hash(k);; (i += 1) &= (N - 1)) {
            if (not m_used.test(i)) return 0;
            if (m_keys[i] == k) return 1;
        }
    }

private:
    static constexpr int LG = 20;
    static constexpr int N = 1 << LG;
    static constexpr ull r = 11995408973635179863ULL;
    static constexpr uint hash(const ull a) { return (a * r) >> (64 - LG); }
    std::bitset<N> m_used;
    K m_keys[N];
};

constexpr int N = 1e5 + 5;
constexpr int B = 500;
vi a[N];
hashset<ll> edges;
vector<pair<int, bitset<N>>> big;

void add_edge(int x, int y) {
    edges.insert(x * (1LL << 32) + y);
}

bool check_edge(int x, int y) {
    return edges.contains(x * (1LL << 32) + y);
}

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) {
        int x, y; cin >> x >> y;
        a[x].eb(y);
        add_edge(x, y);
    }
    int ans = 0;
    rep(x, N) {
        if(a[x].size() > B) {
            bitset<N> b;
            for(int y: a[x]) b[y] = 1;
            big.eb(x, move(b));
        }
        else {
            sort(all(a[x]));
            for(int i = 0; i < a[x].size(); i++) {
                for(int j = i + 1; j < a[x].size(); j++) {
                    int y1 = a[x][i], y2 = a[x][j], l = y2 - y1;
                    ans += (x + l < N) && check_edge(x + l, y1) && check_edge(x + l, y2);
                    ans += (x - l >= 0) && a[x - l].size() > B && check_edge(x - l, y1) && check_edge(x - l, y2);
                }
            }
        }
    }
    for(int i = 0; i < big.size(); i++) {
        auto& [x1, b1] = big[i];
        for(int j = i + 1; j < big.size(); j++) {
            auto& [x2, b2] = big[j];
            int l = x2 - x1;
            auto b = b1 & b2;
            ans += (b & (b >> l)).count();
        }
    }
    cout << ans << endl;
}