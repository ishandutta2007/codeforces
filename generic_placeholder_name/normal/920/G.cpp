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

constexpr int N=1e6+1;

vi d[N];

int get(int n, int x) {
  int ans=0;
  for (int u: d[x]) ans+=n/u;
  return n-ans;
}

int32_t main() {
    fastio;
    for(int p=2; p<N; p++) if(d[p].empty()) for(int n=p; n<N; n+=p) {
        int l=d[n].size();
        rep(i, l) d[n].pb(-d[n][i]*p);
        d[n].pb(p);
    }
    int t; cin>>t; while(t--) {
        int x, p, k; cin>>x>>p>>k;
        int base=get(x, p);
        int l=x, r=1e9;
        while(l<r) {
            int m=(l+r)/2;
            if(get(m, p)-base>=k) r=m;
            else l=m+1;
        }
        cout<<l<<endl;
    }
}