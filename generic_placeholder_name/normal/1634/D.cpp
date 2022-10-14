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

int ask(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int ans; cin >> ans;
    assert(ans != -1);
    return ans;
}

pii work(int a, int b, int c, int d) {
    int abc = ask(a, b, c),
        bcd = ask(b, c, d),
        cda = ask(c, d, a),
        dab = ask(d, a, b);
    int m = max({abc, bcd, cda, dab});
    int cnt[4] = {0};
    if(abc == m) cnt[0]++, cnt[1]++, cnt[2]++;
    if(bcd == m) cnt[1]++, cnt[2]++, cnt[3]++;
    if(cda == m) cnt[2]++, cnt[3]++, cnt[0]++;
    if(dab == m) cnt[3]++, cnt[0]++, cnt[1]++;
    pii ord[4] = {mp(0, a), mp(1, b), mp(2, c), mp(3, d)};
    sort(ord, ord + 4, [&](const pii& a, const pii& b) {return cnt[a.fi] > cnt[b.fi];});
    return {ord[0].se, ord[1].se};
}

int mex(int a, int b, int c) { //this is silly
    int x = 1;
    while(1) {
        if(a == x || b == x || c == x) x++;
        else return x;
    }
}

int32_t main() {
    //fastio;
    ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        pii ans = work(1, 2, 3, 4);
        for(int i = 5; i < n; i += 2) ans = work(ans.fi, ans.se, i, i + 1);
        if(n & 1) ans = work(ans.fi, ans.se, n, mex(ans.fi, ans.se, n));
        cout << "! " << ans.fi << ' ' << ans.se << endl;
    }
}