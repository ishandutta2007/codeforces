#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#ifdef flukehn
#define debug(...) fprintf(stderr, __VA_ARGS__);
#else
#define debug(...)
#endif
typedef double db;
typedef long long ll;
typedef long double lf;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
template<typename T>inline void admo(int&a,const T&b){a=(a+b>=mo?a+b-mo:a+b);}
template<typename T>inline void sumo(int&a,const T&b){a=(a-b<0?a-b+mo:a-b);}
template<typename T,typename S>inline bool upmx(T&a,const S&b){return a<b?a=b,1:0;}
template<typename T,typename S>inline bool upmn(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T>inline T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
inline int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
inline int rd(){
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}

const int INF = 0x3f3f3f3f;

const int MX = 500050;

int sum[MX];

int dp[MX];
int tdp[MX];
int main() {
    int N, K, P, i, j;
    N=rd(),K=rd(),P=rd();
    for(i = 1; i <= N; i++) {
		int x=rd();
        sum[i] = (sum[i-1] + x) % P;
    }

    dp[0] = 0;
	for(i = 1; i <= N; i++) dp[i] = -INF;
    for(i = 1; i <= K; i++) {
       // memset(tdp,0x3f,sizeof tdp);
		for(j = 0; j <= N; j++) tdp[j] = 0;

        int mn = dp[0], v = 0;
        for(j = 1; j <= N; j++) {
            tdp[j] = mn;
            if(v > sum[j]) tdp[j]++;

            if(mn < dp[j] || (mn == dp[j] && v < sum[j])) {
                mn = dp[j];
                v = sum[j];
            }
        }
        //memcpy(dp,tdp,sizeof tdp);
		for(j = 0; j <= N; j++) dp[j] = tdp[j];
    }
    return !printf("%d\n", dp[N] * P + sum[N]);
}