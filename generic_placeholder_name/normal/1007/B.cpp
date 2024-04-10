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

constexpr int N=1e5+1;
int d[N];

inline ll nC3(int n) {return n+n*1LL*(n-1)+n*1LL*(n-1)*(n-2)/6;}
inline ll nC2(int n) {return n+n*1LL*(n-1)/2;}

int32_t main() {
    fastio;
    rep1(i, N-1) for(int j=i; j<N; j+=i) d[j]++;
    int t; cin>>t;
    while(t--) {
        int a, b, c; cin>>a>>b>>c;
        int ab=gcd(a, b), bc=gcd(b, c), ac=gcd(a, c), abc=gcd(ab, c);
        int fabc=d[abc],
            fab=d[ab]-d[abc], fbc=d[bc]-d[abc], fac=d[ac]-d[abc],
            fa=d[a]-fab-fac-fabc, fb=d[b]-fab-fbc-fabc, fc=d[c]-fac-fbc-fabc;
        ll ans=0;
        ans+=nC3(fabc);
        ans+=nC2(fab)*d[c]+nC2(fbc)*d[a]+nC2(fac)*d[b]+nC2(fabc)*(fa+fb+fc+fab+fbc+fac);
        int v[]={fabc, fab, fbc, fac, fa, fb, fc};
        rep(i, 7) rep(j, i) rep(k, j) ans+=v[i]*1LL*v[j]*v[k];
        ans-=1LL*fa*fb*fab;
        ans-=1LL*fa*fc*fac;
        ans-=1LL*fb*fc*fbc;
        cout<<ans<<endl;
    }
}