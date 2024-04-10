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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 30005;
int cnt[26];
bool vis[N];

template<typename T>
__attribute__((always_inline)) void smin(T& a, const T& b) {a = a < b ? a : b;}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for(char c: s) cnt[c - 'A']++;
    sort(cnt, cnt + 26, greater<>{});
    int ans = INT_MAX;
    memset(vis, 0, n * sizeof(bool));
    vis[0] = 1;
    for(int c = 0; c < 26; c++) {
        for(int i = n - 1; ~i; i--) if(vis[i]) {
            if(i + cnt[c] >= n) {
                if(i + cnt[c] + m <= k) return void(cout << "0\n");
                else smin(ans, (n - i) * (i + cnt[c] + m - k));
            }
            else vis[i + cnt[c]] = 1;
        }
    }
    swap(n, m);
    memset(vis, 0, n * sizeof(bool));
    vis[0] = 1;
    for(int c = 0; c < 26; c++) {
        for(int i = n - 1; ~i; i--) if(vis[i]) {
            if(i + cnt[c] >= n) {
                if(i + cnt[c] + m <= k) return void(cout << "0\n");
                else smin(ans, (n - i) * (i + cnt[c] + m - k));
            }
            else vis[i + cnt[c]] = 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) solve();
}