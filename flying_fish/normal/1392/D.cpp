
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


char str[maxn];
int dp[maxn][2][2];//front
//=0: L;
bool check(int x,int y,int z) {//xy; check y
	if (x==0&&z==1) return 1;
	if (x==1&&z==0) return 1;
	if (x==1&&y==0&&z==1) return 1;
	if (x==0&&y==1&&z==0) return 1;
	return 0;
}
int main() {
	int T,_; T=1;
	scanf("%d",&T);
	FOR(_,1,T){
		int n,p,i,j,k;
		scanf("%d",&n);
		scanf("%s",str+1);
		str[n+1]=str[1];
		str[n+2]=str[2];
		int ans=INF,x,y;
		REP(x,2) REP(y,2) {
			FOR(p,1,2) REP(i,2) REP(j,2) {
				dp[p][i][j]=INF;
			} dp[2][x][y]=0;
			//CHECK
			// printf("cal %d %d\n",x,y);
			FOR(p,3,n+2) {//check okay
				REP(i,2) REP(j,2) dp[p][i][j]=INF;
				REP(k,2) {
					char c;
					if (k==0) c='L';
					else c='R';
					REP(i,2) REP(j,2) {
						if (check(i,j,k)) {
							min_(dp[p][j][k],dp[p-1][i][j]+(str[p]!=c));
						}
					}
				}
				// printf("dp: %d-%d %d %d %d\n",p,dp[p][0][0],dp[p][0][1],dp[p][1][0],dp[p][1][1]);
			}
			// printf("now-ans=%d\n",dp[n+2][x][y]);
			min_(ans,dp[n+2][x][y]);
		}
		printf("%d\n",ans);
	}
}
/*
10
6
LRRRRL
*/