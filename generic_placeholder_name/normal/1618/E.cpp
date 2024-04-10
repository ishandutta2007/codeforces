#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

optional<vi> solve() {
    int n; cin >> n;
    vi b(n);
    rep(i, n) cin >> b[i];
    ll sb = accumulate(all(b), 0LL);
    ll p = n * 1LL * (n + 1) / 2;
    if(sb % p != 0) return {};
    ll sa = sb / p;
    vi ans(n);
    rep(i, n) {
        ll df = b[(i ? i : n) - 1] - b[i] + sa;
        if(df % n != 0 || df <= 0) return {};
        ans[i] = df / n;
    }
    return ans;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        auto ans = solve();
        if(ans) {
            cout << "YES\n";
            for(auto& x: ans.value()) cout << x << ' ';
            cout << endl;
        }
        else cout << "NO\n";
    }
}