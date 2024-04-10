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

constexpr int N=25000;
constexpr double INF=1e18;

int x[N], y[N], dx[N], dy[N], s[N], n;
double vx[N], r[N], ans=INF;

template<typename T>
inline void chmin(T& a, T b) {a=a<b?a:b;}

int32_t main() {
    fastio;
    cin>>n;
    rep(i, n) {
        cin>>x[i]>>y[i]>>dx[i]>>dy[i]>>s[i];
        r[i]=s[i]/sqrt(dx[i]*dx[i]+dy[i]*dy[i]);
		vx[i]=dx[i]*r[i];
    }
    rep(i, n) rep(j, i) {
        const int det=dx[j]*dy[i]-dx[i]*dy[j];
        if(!det) {
            if((x[i]-x[j])*dy[i]!=(y[i]-y[j])*dx[i]) continue;
            if(((x[i]-x[j])^dx[j])>=0) chmin(ans, (x[i]-x[j])/vx[j]);
            if(((x[j]-x[i])^dx[i])>=0) chmin(ans, (x[j]-x[i])/vx[i]);
            if(vx[i]!=vx[j]) {
                const double val=(x[i]-x[j])/(vx[j]-vx[i]);
                if(val>0) chmin(ans, val);
            }
        }
        else {
            const double val1=1.0*((x[i]-x[j])*dy[j]-(y[i]-y[j])*dx[j])/det;
            const double val2=1.0*((x[i]-x[j])*dy[i]-(y[i]-y[j])*dx[i])/det;
            if(val1>=0&&val2>=0) chmin(ans, max(val1/r[i], val2/r[j]));
        }
    }
    if(ans==INF) cout<<"No show :(\n";
    else cout<<setprecision(10)<<ans<<endl;
}