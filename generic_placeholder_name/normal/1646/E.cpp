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

/*
1000000000000000 1000000000000000000


999999984137699261708929508084966

=====
Used: 1621 ms, 56312 KB
*/


typedef __int128_t i128;

std::ostream& operator<< (std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if(s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

ll calc(int lvl, ll m) {
    static gp_hash_table<ll, i128> dp;
    static gp_hash_table<ll, ll> states;
    static vector<pll> new_states;
    dp.clear();
    states.clear();
    vector<i128> mx(lvl);
    rep1(i, lvl - 1) {
        int g = gcd(i, lvl);
        mx[i / g] = i128(1) * m * i / lvl;
    }
    vector<pair<i128, int>> p;
    rep(i, lvl) if(mx[i]) p.eb(mx[i], i);
    sort(rall(p));
    for(auto& [mx, i]: p) {
        for(auto& [j, cnt]: states) {
            ll nxt = j / gcd((ll)i, j) * i;
            new_states.eb(nxt, -cnt);
            dp[nxt] -= mx / nxt * cnt;
        }
        dp[i] += mx / i;
        states[i]++;
        for(auto& [v, c]: new_states) states[v] += c;
        new_states.clear();
    }
    i128 ans = 0;
    for(auto& [_, f]: dp) ans += f;
    return ans;
}

int32_t main() {
    fastio;
    ll n, m; cin >> n >> m;
    int l = __lg(n);
    vector<ll> loss(l + 1), cnt(l + 1);
    loss[1] = 0; cnt[1] = n - 1;
    for(int i = 2; i <= l; i++) {
        loss[i] = calc(i, m);
        cnt[i] = (ll)pow(n + .5, 1. / i) - 1;
    }
    for(int i = l; i; i--) {
        for(int j = i + i; j <= l; j += i) cnt[i] -= cnt[j];
    }
    i128 ans = 1;
    for(int i = 1; i <= l; i++) ans += (i128)(m - loss[i]) * cnt[i];
    cout << ans << endl;
}