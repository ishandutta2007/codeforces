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

constexpr int N = 10, M = 52;

vi s[N];
int pos[N][M][2];
vi dp[M][1 << N];

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        rep(i, n) s[i].clear();
        rep(i, n) rep(j, M) rep(k, 2) pos[i][j][k] = -1;
        rep(i, M) rep(j, 1 << n) dp[i][j].clear();
        rep(i, n) {
            string t; cin >> t;
            for(char c: t) s[i].pb(c <= 'Z' ? c - 'A' : c - 'a' + M / 2);
        }
        nth_element(s, s, s + n, [&](const vi& a, const vi& b) {return a.size() < b.size();});
        rep(i, n) rep(j, s[i].size()) {
            int c = s[i][j];
            pos[i][c][!!~pos[i][c][0]] = j;
        }
        for(int c: s[0]) {
            rep(msk, 1 << n) {
                bool ok = 1;
                rep(i, n) ok &= !!~pos[i][c][(msk >> i) & 1];
                if(ok && dp[c][msk].empty()) dp[c][msk].pb(c);
            }
            rep(msk, 1 << n) if(!dp[c][msk].empty()) {
                rep(d, M) {
                    int nmsk = 0;
                    rep(i, n) {
                        if(pos[i][c][(msk >> i) & 1] < pos[i][d][0]) {}
                        else if(pos[i][c][(msk >> i) & 1] < pos[i][d][1]) nmsk ^= 1 << i;
                        else {nmsk = -1; break;}
                    }
                    if(~nmsk && dp[c][msk].size() >= dp[d][nmsk].size()) {
                        dp[d][nmsk] = dp[c][msk];
                        dp[d][nmsk].pb(d);
                    }
                }
            }
        }
        vi ans;
        rep(c, M) rep(i, 1 << n) if(ans.size() < dp[c][i].size()) ans = dp[c][i];
        cout << ans.size() << endl;
        for(int x: ans) cout << char(x < M / 2 ? x + 'A' : x + 'a' - M / 2);
        cout << endl;
    }
}