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
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll N=998244353;

ll exp(ll a, ll b, ll mod) {
    if(b==0) return 1;
    else {
        ll x=exp(a, b/2, mod);
        if(b%2) return (((x*x)%mod)*a)%mod;
        else return (x*x)%mod;
    }
}

ll inv(ll x) {return exp(x, N-2, N);}

ll d(ll x, ll y) {return (x*inv(y))%N;}
 
int32_t main() {
    fastio;
    int n; cin>>n; vi a[n]; int num[1000001]={0}, give[n];
    rep(i, n) {
        int l; cin>>l; a[i].assign(l, 0);
        rep(j, l) {cin>>a[i][j]; num[a[i][j]]++;}
    }
    rep(i, 1000001) num[i]=(num[i]*d(1, n))%N;
	rep(i, n) {
	    ll sum=0;
	    for (auto j: a[i]) sum+=num[j]; sum%=N;
        give[i]=d(sum, a[i].size());
	}
    ll sum=0;
    rep(i, n) sum+=give[i]; sum%=N;
    sum=d(sum, n);
    cout<<sum<<endl;
}