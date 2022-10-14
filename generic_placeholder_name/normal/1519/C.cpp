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

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vvll s(n);
        vi _a(n), _b(n);
        rep(i, n) cin >> _a[i];
        rep(i, n) cin >> _b[i];
        rep(i, n) s[--_a[i]].pb(_b[i]);
        rep(i, n) sort(rall(s[i]));
        vi idx(n); iota(all(idx), 0);
        sort(all(idx), [&](int x, int y) {return s[x].size() > s[y].size();});
        rep(i, n) rep1(j, (int)s[i].size() - 1) s[i][j] += s[i][j - 1];
        int ptr = n - 1;
        rep1(T, n) {
            ll ans = 0;
            while(ptr && s[idx[ptr]].size() < T) --ptr;
            rep(j, ptr + 1) {
                int i = idx[j];
                ll last = (s[i].size() / T) * T - 1;
                ans += (~last ? s[i][last] : 0LL);
            }
            cout << ans << ' ';
        }
        cout << endl;
    }
}