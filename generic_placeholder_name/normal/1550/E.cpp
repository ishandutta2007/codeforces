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

namespace que {
    constexpr int K = 17;
    constexpr int M = 1 << (K - 1);
    pii que[K][M];
    int l[K], r[K];

    void reset() {
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
    }

    const pii& top(int k) {return que[k][l[k]];}

    bool empty(int k) {return l[k] == r[k];}

    void push(int k, const pii& a) {que[k][r[k]++] = a;}

    void pop(int k) {l[k]++;}
};

int32_t main() {
    fastio;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int l = 0, r = n / k;
    while(l < r) {
        int m = (l + r + 1) / 2;
        vvb ok(k, vb(n));
        rep(i, k) {
            char c = 'a' + i;
            int lst = -1;
            rep(j, n) {
                if(s[j] != c && s[j] != '?') lst = j;
                ok[i][j] = (j - lst >= m);
            }
        }
        vb dp(1 << k, 0);
        auto upd = [&](int idx, int msk) -> void {
            if(dp[msk]) return;
            dp[msk] = 1;
            rep(i, k) if(!((msk >> i) & 1)) que::push(i, {idx, msk});
        };
        que::reset();
        upd(-1, 0);
        rep(i, n) {
            rep(j, k) if(ok[j][i]) {
                while(!que::empty(j) && que::top(j).fi <= i - m) {
                    int msk = que::top(j).se;
                    upd(i, msk | (1 << j));
                    que::pop(j);
                }
            }
        }
        if(dp[(1 << k) - 1]) l = m;
        else r = m - 1;
    }
    cout << l << endl;
}