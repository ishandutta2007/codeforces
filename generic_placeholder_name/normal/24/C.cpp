        #include <bits/stdc++.h>
        #include <ext/pb_ds/assoc_container.hpp>
        #include <ext/pb_ds/trie_policy.hpp>
         
        #pragma 03
         
        using namespace std;
        using namespace __gnu_pbds;
         
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
        typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
        typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;
         
        #define fi first
        #define se second
        #define pb push_back
        #define mp make_pair
        #define gcd __gcd
        #define lcm(a, b) (a)*(b)/gcd((a), (b))
        #define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
        #define rep(i, n) for (int i=0; i<(n); i++)
        #define all(x) (x).begin(), (x).end()
        #define rall(x) (x).rbegin(), (x).rend()
         
         
        int32_t main() {
            fastio;
            ll n, j; cin>>n>>j; j%=n*2;
            pll m; cin>>m.fi>>m.se;
            pll a[n]; rep(i, n) cin>>a[i].fi>>a[i].se;
            for(int i=0; i<j; i++) {
                m.fi=2*a[i%n].fi-m.fi;
                m.se=2*a[i%n].se-m.se;
            }
            cout<<m.fi<<' '<<m.se;
        }