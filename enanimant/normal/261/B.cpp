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

#define MAXN 55

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

int N,P,arr[MAXN];
ll dp[MAXN][MAXN][MAXN]; //n,take,sum
ll sum[MAXN];

inline void init_dp(int ignore){
    memset(dp,0,sizeof dp);
    dp[0][0][0] = 1;
    for(int i=1; i<=N; i++){
        dp[i][0][0] = 1;
        if(i == ignore){
            memcpy(dp[i],dp[i-1],sizeof dp[i-1]);
            continue;
        }
        for(int take=1; take<=i; take++){
            for(int sum=1; sum<=P; sum++){
                dp[i][take][sum] = dp[i-1][take][sum];
                if(sum >= arr[i])
                    dp[i][take][sum]+=dp[i-1][take-1][sum-arr[i]];
            }
        }
    }
}

long long choose(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; i++){
        res*=(n + 1 - i);
        res/=i;
    }
    return res;
}

int main(){
    fastio; cin >> N;
    int ss = 0;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
        ss+=arr[i];
    }
    cin >> P;
    if(ss <= P){
        cout << N << endl;
        return 0;
    }
    for(int over=1; over<=N; over++){
        init_dp(over);
        for(int s=P+1; s<P+arr[over]; s++){
            if(s < arr[over]) continue;
            int rem_sum = s-arr[over];
            for(int take=0; take<=N-1; take++){
                ll w = dp[N][take][rem_sum];
                sum[take]+=w;
            }
        }
    }
    init_dp(-1);
    ld res = 0;
    for(int take=1; take<=N; take++){
        ld w = (ld)dp[N][take][P]*take/choose(N,take);
        res+=w;
    }
    for(int t=1; t<N; t++){
        ld am = (ld)sum[t]*t/choose(N-1,t)/N;
        res+=am;
    }
    cout << fixed << setprecision(4) << res << endl;
}