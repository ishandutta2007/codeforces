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

constexpr int N=5e5+1;
constexpr ll MOD=123456789101119, p=31;
ll pw[N], rev[N];

void init() {
    pw[0]=1; rev[0]=MOD-2;
    rep1(i, N-1) {
        pw[i]=pw[i-1]*p%MOD;
        rev[i]=(3*MOD-3*pw[i])%MOD;
    }
}

vi elem[N];
gp_hash_table<ll, int> m;
ll pf[N];

int32_t main() {
    fastio;
    init();
    int n; cin>>n;
    int ptr=0; ll ans=0;
    m[0]=1;
    rep1(i, n) {
        int x; cin>>x;
        elem[x].pb(i);
        pf[i]=pf[i-1];
        if(elem[x].size()%3==0) pf[i]=(3*MOD+pf[i]-3*pw[x])%MOD;
        if(elem[x].size()>=4) {
            int r=elem[x][elem[x].size()-4];
            while(ptr<r) m[pf[ptr++]]--;
        }
        (pf[i]+=pw[x])%=MOD;
        ans+=m[pf[i]]; m[pf[i]]++;
    }
    cout<<ans<<endl;
}