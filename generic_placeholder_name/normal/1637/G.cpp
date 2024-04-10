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

//I have no idea what the complexity of this is
//but it seems fast enough in testing

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        if(n == 2) {cout << "-1\n"; continue;}
        int l = __lg(n - 1) + 1, tg = 1 << l;
        vi cnt(tg + 1, 0); rep1(i, n) cnt[i] = 1;
        vector<pii> ans;
        auto op = [&](int x, int y) {
            //cout << x << ' ' << y << endl;
            assert(x >= y);
            ans.eb(x, y);
            assert(cnt[x] > 0 && cnt[y] > 0);
            cnt[x]--, cnt[y]--;
            cnt[x + y]++, cnt[x - y]++;
        };
        auto process = [&](int n, int m, const auto& self) -> void {
            n -= !(n & 1);
            //cout << "process " << n << ' ' << m << endl;
            int lg = __lg(n);
            int j = (1 << lg) - 1;
            int nxt = 0;
            for(int i = (1 << lg) + 1; i <= n; i += 2, j -= 2) {
                int x = cnt[i * m];
                rep(_, x) op(i * m, j * m);
                if(!nxt && cnt[j * m]) nxt = j;
            }
            if(!nxt) nxt = j;
            if(nxt > 2) self(nxt, m, self);
        };
        rep(i, l) process(n >> i, 1 << i, process);
        if(!cnt[0]) {
            rep(i, l) if(cnt[1 << i] >= 2) {
                op(1 << i, 1 << i); break;
            }
        }
        rep(i, l) {
            while(cnt[1 << i]) {
                op(1 << i, 0);
                op(1 << i, 1 << i);
            }
        }
        while(cnt[0]) op(tg, 0);
        assert(cnt[tg] == n);
        cout << ans.size() << endl;
        for(auto& [x, y]: ans) cout << x << ' ' << y << endl;
    }
}