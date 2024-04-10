#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma,popcnt")

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
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

bool ask(ll x) {
    cout << "? " << x << endl;
    string R; cin >> R;
    return R[0] == '1';
}

int32_t main() {
    //fastio;
    int T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        ll l = 1, r = n - 1, ans = n, p = 1;
        for(ll k = n / 2; k + 1 < n; k = ((k + n) / 2 + n) / 2) p += (k + n) / 2 - k;
        ask(p);
        bool dir = 1;
        while(l <= r) {
            ll m = (l + r) / 2;
            if(dir) p += m;
            else p -= m;
            dir ^= 1;
            if(ask(p)) r = m - 1, ans = m;
            else l = m + 1;
        }
        cout << "= " << ans << endl;
    }
}