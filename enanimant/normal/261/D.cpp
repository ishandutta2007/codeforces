#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 100005

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

const ld PI = (ld)4*atanl(1);

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int T,N,MV,K,arr[MAXN];
vector<int> pos[MAXN];
ll** dp;

inline void reset(){
    for(int i=1; i<=MV; i++) pos[i].clear();
    for(int i=0; i<=N; i++)
        for(int k=0; k<=MV; k++)
            dp[i][k] = LL_INF;
}

int main(){
    fastio; cin >> T >> N >> MV >> K;
    dp = new ll*[N+1];
    for(int i=0; i<=N; i++)
        dp[i] = new ll[MV+1];
    while(T--){
        reset();
        for(int i=1; i<=N; i++){
            cin >> arr[i];
            pos[arr[i]].pb(i);
        }
        for(int i=1; i<=MV; i++){
            if(pos[i].empty()) continue;
            dp[1][i] = pos[i][0];
        }
        for(int i=1; i<=MV; i++)
            dp[1][i] = min(dp[1][i-1],dp[1][i]);
        int res = 1;
        for(int len=2; len<=N; len++){
            for(int lst=len; lst<=MV; lst++){
                ll t = dp[len-1][lst-1];
                if(t == LL_INF || pos[lst].empty()) continue;
                int p = (int)((t-1)%N)+1;
                auto it = upper_bound(all(pos[lst]),p);
                if(it != pos[lst].end()) dp[len][lst] = t+(*it)-p;
                else dp[len][lst] = t+N-p+pos[lst][0];
            }
            for(int lst=len; lst<=MV; lst++){
                if((dp[len][lst]+N-1)/N <= K) res = len;
                dp[len][lst] = min(dp[len][lst],dp[len][lst-1]);
            }
        }
        cout << res << endl;
    }
}
/*
1 3 5 2
2 3 1
ans=3
 */