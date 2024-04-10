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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

constexpr int MOD = 1e9 + 7;
int add(int a, int b) {
    return ((a += b) >= MOD) ? a - MOD : a;
}

constexpr int N = 2e5 + 5;
int v[N];
int a[N];
gp_hash_table<int, null_type, custom_hash> m;

bool test(int x) {
    for(; x; x >>= (2 - (x & 1))) {
        if(m.find(x) != m.end()) return 0;
        if((x & 3) == 2) return 1;
    }
    return 1;
}

int32_t main() {
    fastio;
    int n, p; cin >> n >> p;
    rep(i, n) cin >> a[i];
    sort(a, a + n);
    rep(i, n) {
        if(test(a[i])) v[__lg(a[i])]++;
        m.insert(a[i]);
    }
    v[1] = add(v[1], v[0]);
    for(int i = 2; i < p; i++) v[i] = add(v[i], add(v[i - 1], v[i - 2]));
    cout << accumulate(v, v + p, 0LL) % MOD << endl;
}