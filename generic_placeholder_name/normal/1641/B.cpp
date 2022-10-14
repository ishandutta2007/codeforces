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

bool check(vi a) {
    if(a.size() & 1) return 0;
    sort(all(a));
    for(int i = 0; i < a.size(); i += 2) if(a[i] != a[i + 1]) return 0;
    return 1;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vi a(n); rep(i, n) cin >> a[i];
        if(!check(a)) {cout << "-1\n"; continue;}
        vector<pii> adds;
        vi segs;
        int cnt = 0;
        auto ins = [&](int idx, int v) {
            rep(_, 2) a.insert(a.begin() + idx, v);
            adds.eb(cnt + idx, v);
        };
        while(!a.empty()) {
            int p = find(a.begin() + 1, a.end(), a[0]) - a.begin();
            for(int i = 1; i < p; i++) ins(p + i, a[i]);
            segs.pb(2 * p);
            a.erase(a.begin(), a.begin() + (2 * p));
            cnt += 2 * p;
        }
        cout << adds.size() << endl;
        for(auto& [a, b]: adds) cout << a << ' ' << b << endl;
        cout << segs.size() << endl;
        for(auto& x: segs) cout << x << ' '; cout << endl;
    }
}