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

constexpr ll MOD=1e9+7;
ll exp(ll a, ll b, const ll& m=MOD) {
    if(!b) return 1;
    else {
        ll x=exp(a, b/2);
        if(b&1) return x*x%m*a%m;
        else return x*x%m;
    }
}

constexpr ll INF=1e18;
ll exp_cap(ll a, ll b) {
    ll tmp=1;
    while(b--) {
        tmp*=a;
        if(tmp>1e6) return INF;
    }
    return tmp;
}

inline void pr(ll& a, ll b) {a=min(a+b, INF);}

ll solve(ll a[], int p, int n) {
    if(p==1) return n&1;
    sort(a, a+n, greater<int>());
    vll el, occ;
    rep(i, n) {
        if(el.empty()||*el.rbegin()!=a[i]) el.pb(a[i]), occ.pb(1);
        else (*occ.rbegin())++;
    }
    vll diff, cntr; ll d=0;
    rep(i, el.size()) {
        if(i) {
            ll df=exp_cap(p, el[i-1]-el[i]);
            if(df==INF||d>=INF/df) d=INF; else d*=df;
        }
        //cout<<i<<' '<<el[i]<<' '<<d<<endl;
        if(diff.empty()&&occ[i]%2==0) continue;
        else if(diff.empty()) diff.pb(el[i]), pr(d, 1);
        else {
            if(d<=occ[i]) {
                cntr.clear(); diff.clear();
                int rem=occ[i]-d; d=0;
                if(rem%2==0) continue;
                else diff.pb(el[i]), pr(d, 1);
            }
            else {
                d-=occ[i];
                rep(j, occ[i]) cntr.pb(el[i]);
            }
        }
    }
    //for(ll it: diff) cout<<it<<' '; cout<<endl;
    //for(ll it: cntr) cout<<it<<' '; cout<<endl;
    ll ans=0;
    for(ll it: diff) ans=(ans+exp(p, it))%MOD;
    for(ll it: cntr) ans=(ans+MOD-exp(p, it))%MOD;
    return ans;
}

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        int n, p; cin>>n>>p;
        ll a[n]; rep(i, n) cin>>a[i];
        cout<<solve(a, p, n)<<endl;
    }
}