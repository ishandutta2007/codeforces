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
const LL M=998244353;
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

// , 
// , fly_walk=g3
// , fly_walk=g2
// , fly_walk_more=g4
ll l[maxn];
int main() {
	int i;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%I64d",&l[i]);
	scanf("%s",str+1);
	ll ans=0,g3=0,g2=0; bool c3=0;
	FOR(i,1,n) {
		if (str[i]=='G'){
			if (g2&&l[i]){
				ll del=min(g2,l[i]);
				ans+=del*2; g2-=del; g3+=del*2; l[i]-=del;
				//: length=del*2;
				//=4del => 8del+2del;
				//2del->5del
			}
			ans+=l[i]*3;
			g3+=l[i];
			//3del->6del
		} else if (str[i]=='W') {//water
			ans+=l[i]*2;
			g2+=l[i];//more=1
			c3=1;
			//2del->4del
		} else if (str[i]=='L'){
			if (g2&&l[i]){
				ll del=min(g2,l[i]);
				ans+=del*2; g2-=del; l[i]-=del;
			}
			if (g3&&l[i]) {
				ll del=min(g3,l[i]);
				ans+=del*3; g3-=del; l[i]-=del;
			}
			if (c3){
				ans+=l[i]*4; l[i]=0;
			}
			ans+=l[i]*6; l[i]=0;
		}
	}
	printf("%I64d\n",ans);
}
/*
2
10 20
WG

2
10 20
GW
*/