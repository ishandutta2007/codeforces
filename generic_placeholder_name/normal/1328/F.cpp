//resub from alt
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
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main(){
    fastio;
    int n, k; cin>>n>>k; int arr[n]; rep(i, n) cin>>arr[i];
    sort(arr, arr+n);
    vector<pii> a; a.reserve(n);
    rep(i, n) {
        if(a.empty()||arr[i]!=(*a.rbegin()).fi) a.pb({arr[i], 1});
        else a[a.size()-1].se++;
    }
    n=a.size();
    ll pf[n]={0}, sf[n]={0}, dp[n]={}; int cpf[n]={0}, csf[n]={0};
    rep1(i, n-1) {
        cpf[i]=cpf[i-1]+a[i-1].se;
        pf[i]=pf[i-1]+1LL*cpf[i]*(a[i].fi-a[i-1].fi)-a[i-1].se;
    }
    for(int i=n-2; i>=0; i--) {
        csf[i]=csf[i+1]+a[i+1].se;
        sf[i]=sf[i+1]+1LL*csf[i]*(a[i+1].fi-a[i].fi)-a[i+1].se;
    }
    rep(i, n) {
        dp[i]=LLONG_MAX;
        if(a[i].se>=k) dp[i]=0;
        else {
            if(cpf[i]+a[i].se>=k) dp[i]=min(dp[i], pf[i]+k-a[i].se);
            if(csf[i]+a[i].se>=k) dp[i]=min(dp[i], sf[i]+k-a[i].se);
        }
        if(dp[i]==LLONG_MAX) dp[i]=pf[i]+sf[i]+k-a[i].se;
    }
    ll ans=LLONG_MAX; rep(i, n) ans=min(ans, dp[i]);
    cout<<ans<<endl;
}