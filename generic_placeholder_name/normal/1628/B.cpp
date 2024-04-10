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
        int n; cin >> n;
        vector<string> a(n);
        rep(i, n) cin >> a[i];
        [&](){
            rep(i, n) if(a[i].size() == 1) {cout << "YES\n"; return;}
            set<string> allowed;
            for(int i = n - 1; i >= 0; i--) {
                if(a[i][0] == a[i].back()) {cout << "YES\n"; return;}
                if(a[i].size() == 2) {
                    reverse(all(a[i]));
                    if(allowed.count(a[i])) {cout << "YES\n"; return;}
                    for(char c = 'a'; c <= 'z'; c++) {
                        if(allowed.count(c + a[i])) {cout << "YES\n"; return;}
                    }
                    reverse(all(a[i]));
                    allowed.insert(a[i]);
                }
                else {
                    reverse(all(a[i]));
                    if(allowed.count(a[i])) {cout << "YES\n"; return;}
                    string aaa;
                    aaa.pb(a[i][1]), aaa.pb(a[i][2]);
                    if(allowed.count(aaa)) {cout << "YES\n"; return;}
                    reverse(all(a[i]));
                    allowed.insert(a[i]);
                }
            }
            cout << "NO\n";
        }();
    }
}