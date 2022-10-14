#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
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

int solve_max(vi& a, int k) {
    #define n (int)a.size()
    int one=0, two=0;
    vb vis(n, 0);
    rep(i, n) if(!vis[i]) {
        vis[i]=1;
        int j=i, cur=1; while(a[j]!=i) j=a[j], vis[j]=1, cur++;
        two+=(cur>>1); one+=cur&1;
    }
    return min(k, two)*2+min(max(k-two, 0), one);
    #undef n
}

constexpr int K=5e5+1;
int solve_min(vi& a, int k) {
    #define n (int)a.size()
    //decomp into components
    vb vis(n, 0);
    vi c(n+1, 0);
    rep(i, n) if(!vis[i]) {
        vis[i]=1;
        int j=i, cur=1; while(a[j]!=i) j=a[j], vis[j]=1, cur++;
        c[cur]++;
    }
    ll tot=0; rep(i, n+1) tot+=i*1LL*c[i]; if(tot!=n) cout<<tot<<endl;
    int prv=k;
    k=min(k, n-k);
    bitset<K> dp; dp[0]=1;
    rep(i, k+1) if(c[i]) {
        for(int x=0; (1<<x)<=c[i]; x++) {
            dp|=(dp<<(i<<x));
            c[i]-=(1<<x);
        }
        dp|=(dp<<(i*c[i]));
    }
    return dp[k]?prv:prv+1;
    #undef n
}

int32_t main() {
    fastio;
    int n, k; cin>>n>>k; vi a(n); rep(i, n) cin>>a[i], --a[i];
    cout<<solve_min(a, k)<<' '<<solve_max(a, k)<<endl;
}