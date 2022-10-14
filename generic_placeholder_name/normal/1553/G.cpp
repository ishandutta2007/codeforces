#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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

constexpr int M = 1e6 + 1;
constexpr int N = 1.5e5;

bitset<M + 1> isprime;
bitset<M + 1> exists;
vector<int> primes[M + 1];
int a[N];

namespace DSU {
    int d[M + 1];

    struct __init {
        __init() {memset(d, -1, sizeof(d));}
    } __INIT;

    int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}

    void join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y]; d[y] = x;
    }

    bool is_joined(int x, int y) {return find(x) == find(y);}
};

gp_hash_table<ll, null_type> edges;

void insert_edge(int x, int y) {
    x = DSU::find(x), y = DSU::find(y);
    if(x == y) return;
    if(x > y) swap(x, y);
    edges.insert(x * (1LL << 32) + y);
}

bool check_edge(int x, int y) {
    x = DSU::find(x), y = DSU::find(y);
    assert(x != y);
    if(x > y) swap(x, y);
    return edges.find(x * (1LL << 32) + y) != edges.end();
}

int32_t main() {
    fastio;
    int n, q; cin >> n >> q;
    rep(i, n) cin >> a[i], exists[a[i]] = 1;
    isprime.set();
    for(int i = 2; i <= M; i++) if(isprime[i]) {
        if(exists[i - 1]) primes[i].pb(i);
        for(int j = i * 2; j <= M; j += i) {
            if(exists[j]) DSU::join(i, j);
            if(exists[j - 1]) primes[j].pb(i);
            isprime[j] = 0;
        }
    }
    rep(i, n) {
        for(int p: primes[a[i] + 1]) {
            insert_edge(a[i], p);
            for(int q: primes[a[i] + 1]) if(p < q) {
                insert_edge(p, q);
            }
        }
    }
    while(q--) {
        int i, j; cin >> i >> j; --i, --j;
        if(DSU::is_joined(a[i], a[j])) puts("0");
        else if(check_edge(a[i], a[j])) puts("1");
        else puts("2");
    }
}