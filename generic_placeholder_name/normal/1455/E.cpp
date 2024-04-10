#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    constexpr ll INF=1e18;
    int T; cin>>T; while(T--) {
        ll x[4], y[4];
        rep(i, 4) cin>>x[i]>>y[i];
        ll ans=INF;
        auto solve = [&](ll d) {
            int id[4];
            iota(id, id+4, 0);
            ll ans=INF;
            do {
                ll px[4], py[4];
                px[0]=x[id[0]];
                px[1]=x[id[1]]-d;
                px[2]=x[id[2]];
                px[3]=x[id[3]]-d;
                py[0]=y[id[0]];
                py[1]=y[id[1]];
                py[2]=y[id[2]]-d;
                py[3]=y[id[3]]-d;
                sort(px, px+4);
                sort(py, py+4);
                ans=min(ans, px[3]+px[2]-px[1]-px[0]+py[3]+py[2]-py[1]-py[0]);
            } while(next_permutation(id, id+4));
            return ans;
        };
        rep(i, 4) rep(j, i) ans=min(ans, solve(abs(x[i]-x[j])));
        rep(i, 4) rep(j, i) ans=min(ans, solve(abs(y[i]-y[j])));
        cout<<ans<<endl;
    }
}