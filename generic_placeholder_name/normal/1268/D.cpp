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

constexpr int N = 2000;
array<bitset<N>, N> adj, rev_adj;
bitset<N> mark;
bitset<N> all;

int que[N], l, r;
bitset<N> t;
void bfs(const array<bitset<N>, N>& adj, int src) {
    l = 0, r = 1, que[0] = src;
    mark = all; mark[src] = 0;
    while(l < r) {
        int u = que[l++];
        t = mark & adj[u];
        for(int v = t._Find_first(); v < N; v = t._Find_next(v)) {
            que[r++] = v;
            mark[v] = 0;
        }
    }
}

#pragma GCC target("popcnt")
bool check() {
    bfs(adj, 0);
    if(mark.count()) return 0;
    bfs(rev_adj, 0);
    return mark.count() == 0;
}

int32_t main() {
    fastio;
    int n; cin >> n;
    rep(i, n) {
        string s; cin >> s;
        rep(j, n) {
            adj[i][j] = s[j] == '1';
            rev_adj[i][j] = s[j] == '0';
        }
        all[i] = 1;
    }
    if(n <= 6) {
        int ans = INT_MAX, cnt;
        rep(msk, 1 << n) {
            auto flip = [&]() {
                rep(i, n) rep(j, i) if(((msk >> i) ^ (msk >> j)) & 1) {
                    adj[i][j] = !adj[i][j];
                    adj[j][i] = !adj[j][i];
                    rev_adj[i][j] = !rev_adj[i][j];
                    rev_adj[j][i] = !rev_adj[j][i];
                }
            };
            flip();
            if(check()) {
                int p = __builtin_popcount(msk);
                if(ans > p) ans = p, cnt = 1;
                else if(ans == p) ++cnt;
            }
            flip();
        }
        if(ans == INT_MAX) puts("-1");
        else {
            rep1(i, ans) cnt *= i;
            cout << ans << ' ' << cnt << endl;
        }
    }
    else {
        if(check()) puts("0 1");
        else {
            int cnt = 0;
            rep(i, n) {
                auto flip = [&]() {
                    adj[i] = ~adj[i];
                    rev_adj[i] = ~rev_adj[i];
                    rep(j, n) if(j != i) {
                        adj[j][i] = !adj[j][i];
                        rev_adj[j][i] = !rev_adj[j][i];
                    }
                };
                flip();
                cnt += check();
                flip();
            }
            cout << "1 " << cnt << endl;
        }
    }
}