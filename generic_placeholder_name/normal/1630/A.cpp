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

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        if(k == 0) {
            rep(i, n / 2) cout << i << ' ' << n - i - 1 << endl;
        }
        else if(k != n - 1) {
            cout << 0 << ' ' << (k ^ (n - 1)) << endl;
            cout << k << ' ' << n - 1 << endl;
            rep(i, n / 2) if(i != 0 && i != k && i != ((n - 1) ^ k)) cout << i << ' ' << n - i - 1 << endl;
        }
        else if(n == 4) cout << "-1\n";
        else {
            cout << 1 << ' ' << n / 2 - 1 << endl;
            cout << n / 2 << ' ' << 0 << endl;
            cout << n - 1 << ' ' << n - 2 << endl;
            rep(i, n / 2) if(i != 0 && i != 1 && i != n / 2 - 1) cout << i << ' ' << n - i - 1 << endl;
        }
    }
}