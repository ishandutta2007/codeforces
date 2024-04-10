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
template<typename T>inline T powMM(T a, T b) {
	T ret=1;
	for (; b; b>>=1ll,a=(LL)a*a%M)
		if (b&1) ret=(LL)ret*a%M;
	return ret;
}
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}
int n,m,q;
char str[maxn];

//f[1][2]: , ()
int f[maxn][5][5];
int C[maxn*4];
int A[maxn];
int main() {
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",&A[i]);
	sort(A+1,A+1+n);
	int base=1;
	FOR(i,1,n) {
		if (i!=1) {
			if (A[i]-A[i-1]>1) base+=2;
			else base+=A[i]-A[i-1]; 
		} C[base]++;
	} int ans=0;
	// FOR(i,1,base) printf("%d ",C[i]); puts("");
	FOR(i,1,base+1){
		FOR(j,0,2) FOR(k,0,2) f[i][j][k]=-INF;
	} f[1][0][0]=0;
	FOR(i,1,base+1) {
		int more=max(0,(C[i]-6)/3);
		C[i]-=more*3;
		FOR(l,0,C[i]/3) {//3
			FOR(j,0,2) FOR(k,0,2){//
				max_(ans,f[i][j][k]);
				int now=C[i]-l*3;//
				int ok2=min(now,k); now-=ok2;
				int ok1=min(now,j); now-=ok1; now=min(now,2);
				max_(f[i+1][now][ok1],l+ok2+f[i][j][k]+more);
				// if (f[i][j][k]>=0)
				// 	printf("%d - %d - %d: %d  -> %d %d (val=%d)\n",i,j,k,f[i][j][k],now,ok1,l+ok2+f[i][j][k]+more);
			}
		}
	} printf("%d\n",ans);
}
/*
100
1 2 3 4 5 6 7 8 9 10 15 31

19
1 1 2 2 2 2 3 3 3 3 3 3 3 4 4 4 4 5 5

11 2222 3333333 4444 55

*/