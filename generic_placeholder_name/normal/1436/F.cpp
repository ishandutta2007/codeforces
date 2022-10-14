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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int MOD=998244353;
constexpr int N=1e5+1;

inline int add(int a, int b) {return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b) {return add(a, MOD-b);}
inline int mul(int a, int b) {return (a*1LL*b)%MOD;}

#define div __iefhijem8j
inline int exp(int a, int b) {
    if(a>=MOD) a-=MOD;
    if(b<0) b+=MOD-1;
    int res=1;
    for(; b; b>>=1) {
        if(b&1) res=mul(res, a);
        a=mul(a, a);
    }
    return res;
}

inline int inv(int a) {return exp(a, MOD-2);}
inline int div(int a, int b) {return mul(a, inv(b));}

int a[N+1];
int E[N+1];
int u[N+1];
int f[N+1];

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(_, n) {
        int x, f; cin>>x>>f;
        a[x]=f%MOD;
        E[x]=f%(MOD-1);
    }
    u[1]=1;
    for(int i=2; i<=N; i++) {
        if(!f[i]) {
            for(int j=i; j<=N; j+=i) if(!f[j]) f[j]=i;
        }
        if((i/f[i])%f[i]==0) u[i]=0;
        else u[i]=-u[i/f[i]];
    }
    for(int i=1; i<=N; i++) u[i]=add(u[i], MOD);
    int ans=0;
    for(int i=1; i<=N; i++) if(u[i]) {
        int cur=0, cnt=0, cntE=0, sum=0;
        for(int j=i; j<=N; j+=i) {
            sum=add(sum, mul(j, a[j]));
            cnt=add(cnt, a[j]);
            cntE+=E[j]; if(cntE>=MOD-1) cntE-=MOD-1;
        }
        for(int j=i; j<=N; j+=i) {
            cur=add(cur, mul(mul(j, j), mul(a[j], mul(exp(2, cntE-2), sub(cnt, 1)))));
            cur=add(cur, mul(mul(j, sub(sum, j)), mul(a[j], add(mul(exp(2, cntE-3), sub(cnt, 2)), exp(2, cntE-2)))));
        }
        ans=add(ans, mul(u[i], cur));
    }
    cout<<ans<<endl;
}