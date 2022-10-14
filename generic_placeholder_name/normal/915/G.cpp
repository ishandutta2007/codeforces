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

constexpr int MOD=1e9+7;

inline int add(int a, int b) {return (a+b)%MOD;}
inline int sub(int a, int b) {return (a+MOD-b)%MOD;}
inline int mul(int a, int b) {return (a*1LL*b)%MOD;}

inline int exp(int a, int b) {
    if(!b) return 1;
    else {
        int x=exp(a, b/2);
        x=mul(x, x);
        if(b&1) return mul(x, a);
        else return x;
    }
}

constexpr int N=2e6+1;
int u[N], cnt[N];
vi d[N];
int pw[N]; //i^n for i from 0 to N-1
int ans[N];

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    //prep
    rep1(i, N-1) {
        d[i].pb(i);
        if(i==1) u[i]=1;
        else if((i/d[i][1])%d[i][1]==0) u[i]=0;
        else u[i]=-u[i/d[i][1]];
        if(!u[i]) d[i].pop_back();
        else {
            for(int j=2*i; j<N; j+=i) d[j].pb(i);
        }
    }
    rep1(i, N-1) u[i]=add(u[i], MOD);
    rep(i, N) pw[i]=exp(i, n);
    int res=0;
    //end prep
    rep1(i, k) {
        ans[i]=ans[i-1];
        for(int j: d[i]) {
            ans[i]=sub(ans[i], mul(pw[cnt[j]], u[j]));
            cnt[j]++;
            ans[i]=add(ans[i], mul(pw[cnt[j]], u[j]));
        }
        res=add(res, ans[i]^i);
    }
    cout<<res<<endl;
}