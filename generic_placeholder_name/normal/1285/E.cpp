#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        vector<pii> a(n);
        rep(i, n) cin>>a[i].fi>>a[i].se;
        sort(all(a));
        vi pf(n), mx(n);
        pf[0]=1; mx[0]=a[0].se;
        rep1(i, n-1) {
            pf[i]=pf[i-1]+(a[i].fi>mx[i-1]);
            mx[i]=max(mx[i-1], a[i].se);
        }
        vector<pii> sf;
        int ans=0;
        for (int i=n-1; i>0; i--) {
            int x=sf.rend()-upper_bound(rall(sf), mp(mx[i-1], INT_MAX));
            ans=max(ans, x+pf[i-1]);
            pii t=a[i];
            while (!sf.empty()&&sf.back().fi<=t.se) {
                t.se=max(t.se, sf.back().se);
                sf.pop_back();
            }
            sf.pb(t);
        }
        ans=max(ans, (int)sf.size());
        cout<<ans<<endl;
    }
}