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

bool isprime(int x) {
    if(x < 4) return x >= 2;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return 0;
    return 1;
}

constexpr int T = 1e9;
gp_hash_table<int, int> cache;
void precalc() {
    for(int i = 2; i * i <= T; i++) if(isprime(i)) {
        for(ll j = i; j <= T; j *= i) cache[j] = i;
    }
}

pii get_prime(int x) {
    int y;
    if(cache.find(x) != cache.end()) y = cache[x];
    else if(isprime(x)) y = x;
    else return mp(-1, -1);
    int z = 0;
    while(x % y == 0) x /= y, z++;
    return mp(y, z);
}

int32_t main() {
    fastio;
    precalc();
    int T; cin >> T;
    while(T--) {
        [](){
        int x, d; cin >> x >> d;
        if(x % (d * d) != 0) {cout << "NO\n"; return;}
        auto [p, e] = get_prime(d);
        if(!~p) {
            int y = x / (d * d);
            if(y == 1 || isprime(y)) cout << "NO\n";
            else cout << "YES\n";
        }
        else {
            int y = x, z = 0;
            for(; y % p == 0; y /= p) z++;
            int m = (z + 2 * e - 2) / (2 * e - 1);
            int dv = 1;
            rep(_, m) dv *= d;
            int f = x / dv;
            if(f == 1 || isprime(f)) cout << "NO\n";
            else cout << "YES\n";
        }
        }();
    }
}