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
const LL maxn=1e5+107;
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
int nxt[maxn][27],pos[27];//used this
int dp[257][257][257];
char s1[1007],s2[1007],s3[1007];
int l1,l2,l3;
int main() {
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);//used this
	REP(i,27) nxt[n+1][i]=n+1,pos[i]=n+1;
	rFOR(i,0,n) {
		REP(k,27) nxt[i][k]=pos[k];
		if (i) pos[str[i]-'a']=i;
	}
		// REP(k,27) printf("%d ",nxt[0][k]);
	// FOR(i,0,256) FOR(j,0,256) FOR(k,0,256) dp[i][j][k]=n+1;
	dp[0][0][0]=0;//lastpos=0
	while(m--) {
		int o;
		char op[2],ch[2];
		scanf("%s%d",op,&o);
		if (op[0]=='+') {
			scanf("%s",ch);
			int low1=0,low2=0,low3=0;
			if (o==1) low1=l1,s1[l1++]=ch[0];
			if (o==2) low2=l2,s2[l2++]=ch[0];
			if (o==3) low3=l3,s3[l3++]=ch[0];
			// printf("%d-%d-%d\n",low1,low2,low3);
			rep(i,low1,l1+1) rep(j,low2,l2+1) rep(k,low3,l3+1){
				if (!i&&!j&&!k) continue;
				dp[i][j][k]=n+1;
				if (i) min_(dp[i][j][k],nxt[dp[i-1][j][k]][s1[i-1]-'a']);
				if (j) min_(dp[i][j][k],nxt[dp[i][j-1][k]][s2[j-1]-'a']);
				if (k) min_(dp[i][j][k],nxt[dp[i][j][k-1]][s3[k-1]-'a']);
				// printf("%d-%d-%d: %d\n",i,j,k,dp[i][j][k]);
			}
		} else {
			if (o==1) l1--;
			if (o==2) l2--;
			if (o==3) l3--;
		}
		// printf("%d\n",dp[l1][l2][l3]);
		if (dp[l1][l2][l3]<=n) puts("YES");
		else puts("NO");
	}
}
/*
*/