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
typedef long long LL;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF=0x3f3f3f3f;
const LL INFF=0x3f3f3f3f3f3f3f3fll;
const LL M=1e9+7;
const LL maxn=1e6+7;
const double pi=acos(-1.0);
const double eps=0.0000000001;
LL gcd(LL a, LL b) {return b?gcd(b,a%b):a;}
template<typename T>inline void pr2(T x,int k=64) {ll i; REP(i,k) debug("%d",(x>>i)&1); putchar(' ');}
template<typename T>inline void add_(T &A,int B) {A+=B; (A>=M) &&(A-=M);}
template<typename T>inline void mul_(T &A,ll B) {(A*=B)%=M;}
template<typename T>inline void mod_(T &A,ll B=M) {A%=M;}
template<typename T>inline void max_(T &A,T B) {(A<B) &&(A=B);}
template<typename T>inline void min_(T &A,T B) {(A>B) &&(A=B);}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<typename T>inline T powMM(T a, T b) {
	T ret=1;
	for (; b; b>>=1ll,a=(LL)a*a%M)
		if (b&1) ret=(LL)ret*a%M;
	return ret;
}
int n,m,q;
char str[maxn];
int TaskA();
void Task_one() {TaskA();}
void Task_T() {int T; scanf("%d",&T); while (T--) TaskA();}
void Task_more_n() {while (~scanf("%d",&n)) TaskA();}
void Task_more_n_m() {while (~scanf("%d%d",&n,&m)) TaskA();}
void Task_more_n_m_q() {while (~scanf("%d%d%d",&n,&m,&q)) TaskA();}
void Task_more_string() {while (~scanf("%s",str)) TaskA();}

char S[maxn][4];
int son[maxn][2],val[maxn];
int ans[maxn];
int dfs1(int x){
	if (S[x][0]=='N') val[x]=!dfs1(son[x][0]);
	if (S[x][0]=='X') val[x]=dfs1(son[x][0])^dfs1(son[x][1]);
	if (S[x][0]=='A') val[x]=dfs1(son[x][0])&dfs1(son[x][1]);
	if (S[x][0]=='O') val[x]=dfs1(son[x][0])|dfs1(son[x][1]);
	return val[x];
}
void dfs2(int x,int val0,int val1){
	if (S[x][0]=='I') {
		if (val[x]) ans[x]=val0;
		else ans[x]=val1;
	}int i;
	if (S[x][0]=='N') dfs2(son[x][0],val1,val0);
	if (S[x][0]=='X'){
		REP(i,2){
			int t=val[son[x][i^1]];
			if (t) dfs2(son[x][i],val1,val0);
			else dfs2(son[x][i],val0,val1);
		}
	}if (S[x][0]=='A'){
		REP(i,2){
			int t=val[son[x][i^1]];
			if (!t) dfs2(son[x][i],val0,val0);
			else dfs2(son[x][i],val0,val1);
		}
	}if (S[x][0]=='O'){
		REP(i,2){
			int t=val[son[x][i^1]];
			if (t) dfs2(son[x][i],val1,val1);
			else dfs2(son[x][i],val0,val1);
		}
	}
}
int TaskA() {
	int i,k;
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%s",S[i]);
		if (S[i][0]=='I') scanf("%d",&val[i]);
		else if (S[i][0]=='N') scanf("%d",&son[i][0]);
		else scanf("%d%d",&son[i][0],&son[i][1]);
	} dfs1(1);
	// FOR(i,1,n) printf("%d",val[i]);puts("");
	dfs2(1,0,1);
	FOR(i,1,n) if (S[i][0]=='I') printf("%d",ans[i]);
	return 0;
}
void initialize() {}
int main() {
	int startTime=clock();
	//initialize
	initialize();
	debug("/--- initializeTime: %ld milliseconds ---/\n",clock()-startTime);
	Task_one();
}
/*

*/