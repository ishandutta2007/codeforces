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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

ll root(ll n, ll k){
  ll t=powl(n, 1./k)-0.5;
  return t+(powl(t+1, k)-0.5<=n);
}

constexpr int L=60;
int f[L], u[L];

int32_t main() {
    fastio;
    for(int i=2; i<L; i++) if(!f[i]) for(int j=i; j<L; j+=i) if(!f[j]) f[j]=i;
    rep1(i, L-1) {
        if(i==1) u[i]=1;
        else if(f[i/f[i]]==f[i]) u[i]=0;
        else u[i]=-1*u[i/f[i]];
    }
    int t; cin>>t; while(t--) {
        ll n; cin>>n;
        ll ans=0;
        rep1(i, L-1) if(u[i]) ans+=u[i]*(root(n, i)-1);
        cout<<ans<<endl;
    }
}