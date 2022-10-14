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
        vi a(n); rep(i, n) cin >> a[i];
        vi cnt(n + 1);
        rep(i, n) cnt[a[i]]++;
        auto check = [&](int d) -> int {
            int c = 0;
            for(int i = 1; i <= d; i++) c += cnt[i];
            if(c * 2 >= n + k) return 1;
            for(int i = d + 1; i <= n; i++) {
                c -= cnt[i - d];
                c += cnt[i];
                if(c * 2 >= n + k) return i - d + 1;
            }
            return 0;
        };
        int l = 1, r = n, x = 0;
        while(l < r) {
            int m = (l + r) / 2;
            x = check(m);
            if(x) r = m;
            else l = m + 1;
        }
        x = check(l);
        int y = x + l - 1;
        cout << x << ' ' << y << endl;
        int p = -1, c = 0, tot = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] >= x && a[i] <= y) c++;
            else c--;
            if(c > 0) {
                c = 0;
                tot++;
                cout << p + 2 << ' ' << (tot == k ? n : i + 1) << endl;
                p = i;
                if(tot == k) break;
            }
        }
    }
}