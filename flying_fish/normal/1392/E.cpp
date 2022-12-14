
#include <sstream>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <utility>
#include <cassert>
#include <bitset>
using namespace std;
#define REP(I,N) for (I=0;I<N;I++)
#define rREP(I,N) for (I=N-1;I>=0;I--)
#define rep(I,S,N) for (I=S;I<N;I++)
#define rrep(I,S,N) for (I=N-1;I>=S;I--)
#define FOR(I,S,N) for (I=S;I<=N;I++)
#define rFOR(I,S,N) for (I=N;I>=S;I--)
 
#define DEBUG
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define deputs(str) fprintf(stderr, "%s\n",str)
#else
#define debug(...)
#define deputs(str)
#endif // DEBUG
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+107;
const double pi=acos(-1.0);
const double eps=0.0000000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline void pr2(T x,int k=64) {ll i; REP(i,k) debug("%d",(x>>i)&1); putchar(' ');}
template<typename T>inline void add_(T &A,int B,ll MOD=M) {A+=B; (A>=MOD) &&(A-=MOD);}
template<typename T>inline void mul_(T &A,ll B,ll MOD=M) {A=(A*B)%MOD;}
template<typename T>inline void mod_(T &A,ll MOD=M) {A%=MOD; A+=MOD; A%=MOD;}
template<typename T>inline void max_(T &A,T B) {(A<B) &&(A=B);}
template<typename T>inline void min_(T &A,T B) {(A>B) &&(A=B);}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
inline ll powMM(ll a, ll b, ll mod=M) {
    ll ret=1;
    for (; b; b>>=1ll,a=a*a%mod)
        if (b&1) ret=ret*a%mod;
    return ret;
}
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}

ll value[107][107];
void init() {
	int i,j;
	FOR(i,1,26) FOR(j,1,26) {
		if ((i&1)&&(i+j>=3)) {
			value[i][j]=1ll<<(i+j-3);
			// assert(value[i][j]<=1e16);
		}
	}
}
int main() {
	init();
	int T,_; T=1;
	// scanf("%d",&T);
	FOR(_,1,T) {
		int n,i,j;
		scanf("%d",&n);
		FOR(i,1,n) FOR(j,1,n) {
			printf("%lld%c",value[i][j]," \n"[j==n]);
		}
		fflush(stdout);
		ll k; int o,q;
		scanf("%d",&q);
		FOR(o,1,q) {
			ll p=0; scanf("%lld",&p);
			int x=1,y=1;
			// printf("1 1\n");
			FOR(k,0,n+n-3) {
				printf("%d %d\n",x,y);
				ll noww=p&(1ll<<k);
				if (value[x][y+1]==noww) y=y+1;
				else x=x+1;
				assert(value[x][y]==noww);
				// printf("noww=%lld value=%lld\n",noww,value[x][y]);
			}// x=n; y=n;
			printf("%d %d\n",x,y);
			assert(x==n&&y==n);
			fflush(stdout);
		}
	}
}
/*
100 4 9 9
*/