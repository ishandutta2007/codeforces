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

constexpr int N = 300000;
constexpr int M = 8;
int a[N][M];
int label[1 << M];

int32_t main() {
    fastio;
    int n, m; cin >> n >> m;
    rep(i, n) rep(j, m) cin >> a[i][j];
    int l = 0, r = 1e9;
    int x, y;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        memset(label, -1, sizeof(label));
        rep(i, n) {
            int msk = 0;
            rep(j, m) msk |= (a[i][j] >= mid) << j;
            label[msk] = i;
        }
        bool ok = 0;
        for(int i = (1 << m) - 1; ~i; i--) {
            for(int j = (1 << m) - 1; ~j; j--) {
                if((i | j) == ((1 << m) - 1) && ~label[i] && ~label[j]) {
                    x = label[i];
                    y = label[j];
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) l = mid;
        else r = mid - 1;
    }
    if(l) cout << x + 1 << ' ' << y + 1 << endl;
    else cout << "1 1\n";
}