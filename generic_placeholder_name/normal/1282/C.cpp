#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
#define gcd __gcd
#define mp make_pair
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, n) for (ll i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ll f(ll a, ll b, ll va, ll vb, ll t) {
    if(t<=a*va) return t/a;
    else if(t-a*va<=b*vb) return va+(t-a*va)/b;
    else return va+vb;
}

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        ll n, t, a, b; cin>>n>>t>>a>>b; 
        pll val[n]; rep(i, n) cin>>val[i].se; rep(i, n) cin>>val[i].fi;
        sort(val, val+n);
        ll h=0, e=0, ans=0, th=0, te=0;
        rep(i, n) if(val[i].se) th++; else te++;
        rep(i, n) {
            if(e*a+h*b<val[i].fi) ans=max(ans, e+h+f(a, b, te-e, th-h, val[i].fi-e*a-h*b-1));
            if(val[i].se) h++; else e++;
        }
        if(te*a+th*b<=t) ans=te+th;
        cout<<ans<<endl;
    }
}