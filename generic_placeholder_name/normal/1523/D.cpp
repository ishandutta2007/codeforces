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

constexpr int N = 2e5;
constexpr int M = 60;
constexpr int P = 15;

vector<int> v[N];

#pragma GCC target("popcnt")
bitset<N> like[M];
bool large[M];

bitset<N> cur;
bitset<N> all;

bool ok[1 << P];
ll ans;

int32_t main() {
    fastio;
    int n, m, p; cin >> n >> m >> p;
    rep(i, n) {
        string s; cin >> s;
        rep(j, m) like[j][i] = s[j] == '1';
    }
    rep(i, m) large[i] = like[i].count() >= (n + 1) / 2;
    rep(i, n) rep(j, m) if(large[j] && like[j][i]) v[i].pb(j);
    rep(i, n) all[i] = 1;
    rep(_, 10) {
        int p = rng() % n;
        if(v[p].size() <= __builtin_popcountll(ans)) continue;
        int s = v[p].size();
        vi msks(1 << s);
        vb ok(1 << s);
        iota(all(msks), 0);
        sort(all(msks), [&](int x, int y) {return __builtin_popcount(x) < __builtin_popcount(y);});
        for(int msk: msks) {
            ll cur_ans = 0;
            int c = __builtin_popcount(msk);
            if(c <= __builtin_popcountll(ans)) continue;
            else if(c == __builtin_popcountll(ans) + 1) {
                cur = all;
                rep(i, s) if((msk >> i) & 1) cur &= like[v[p][i]];
                if(cur.count() >= (n + 1) / 2) {
                    ll new_ans = 0;
                    rep(i, s) if((msk >> i) & 1) new_ans |= 1LL << v[p][i];
                    cur_ans = new_ans;
                    ok[msk] = 1;
                }
            }
            else {
                int lst = msk & (msk - 1);
                if(!ok[lst]) continue;
                cur = all;
                rep(i, s) if((msk >> i) & 1) cur &= like[v[p][i]];
                if(cur.count() >= (n + 1) / 2) {
                    ll new_ans = 0;
                    rep(i, s) if((msk >> i) & 1) new_ans |= 1LL << v[p][i];
                    cur_ans = new_ans;
                    ok[msk] = 1;
                }
            }
            if(__builtin_popcountll(cur_ans) > __builtin_popcountll(ans)) ans = cur_ans;
        }
    }
    rep(i, m) cout << ((ans >> i) & 1);
}