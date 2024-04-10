// I make this just for fun because i'm done
// Aimi Haraguni >> Konomi Suzuki >> Yui >>  Ikimono Gakari >> Garnidelia >> Kalafina >> Eir Aoi.   .. dude? 
// problems that involves any kind of persistent data structures are the best of the best, are not them?
 
// #pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define ff  first
#define ss second
#define tm1 first
#define tm2 second.first
#define tm3 second.second
#define sz(x) ll(x.size())
#define all(v) (v).begin(), (v).end()
#define fill(x, v) memset(x, v, sizeof(x))
#define FER(i,a,b) for(int i=int(a); i< int(b); ++i)
#define IFR(i,a,b) for(int i=int(a); i>=int(b); --i )
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
 
#define N 210000
// #define M 19
// #define mod3 9
 
#define mod1  998244353
#define mod 1000000007
#define mod2 1000000009
#define mody 998244353
#define bas 987625403
#define sqr(x) (x)*(x)  
#define INF 3000000000000000000
#define N1 1000
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii > tri;
typedef vector<ll> vi;
typedef vector<vi> vv;
typedef vector<ii> vii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> S_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
 
inline ll add(ll a, ll b) { return a+b < mod? a+b : a+b-mod;}
inline ll rem(ll a, ll b) { return a >= b? a - b: a- b + mod;}
inline ll mul(ll a, ll b) { return (long long) a*b%mod;}
inline void Mul(ll &a, ll b) { a = (long long) a*b%mod;}
inline ll bp(ll a, ll p){
    // if(!a) return 1;
    ll ret;
    for(ret = 1; p; p>>=1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1);
    return ret;
}
 
 
static inline void read(ll &result) {
    bool minus = false;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' and ch <= '9') break;
        ch = getchar();
    }
    (ch == '-')? minus = true: result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' or ch > '9') break;
        result = (result<<3)+ (result<<1) + (ch - '0');
    }
    if(minus) result=-result;
}

ll dp[1<<20];
vi v[1<<20];
ll vis[1<<20];
int main(){

    FER(i, 2, 1e3 + 1){
        if(vis[i]) continue;
        for(ll j = sqr(i); j <= 1e6; j += i) vis[j]++;
    }
    FER(i, 2, 1e6 + 1){
    	dp[i] = dp[i - 1];
    	dp[i] += vis[i] == 0;
        // dp[i] = dp[i - 1] + vis[i] == 0;
    }
    auto Q = [&](ll l, ll r){
        if(l) return dp[r - 1] - dp[l - 1];
        return dp[r- 1];
    };
    FER(i, 2, 10){
    	// trace(i, dp[i]);
    }
    ll t; read(t);
    while(t--){
        ll x; read(x);
        ll top = sqrt(x);
        // trace(top + 1, x);
        auto ans = Q(top + 1, x + 1);
        cout<<ans + 1<<"\n";
    }
    return 0;
}