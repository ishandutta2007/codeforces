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
const LL maxn=1<<21|7;
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
int n,m,q;
char str[maxn];
int startTime;
void startTimer() {startTime=clock();}
void printTimer() {debug("/--- Time: %ld milliseconds ---/\n",clock()-startTime);}

int MAX;
struct node{
	unsigned A,B;//0,1
	node(const unsigned _A=0,const unsigned _B=0):A(_A),B(_B){};
	const int operator [] (const int &n) const{
		return ((B>>n)&1)*2+((A>>n)&1);
	}
	void set(int x,int val){
		A|=(val&1)<<x;
		B|=((val&2)>>1)<<x;
	}
	// 1 1: A&x.A
	// 1 0: A^x.A
	// 0 0: !(A&x.A)
	const node operator + (const node &x) const{
		return node(A^x.A,(A&x.A)^(B^x.B));
	}
	const node operator - (const node &x) const{
		return node(A^x.A,(~A&x.A)^(B^x.B));
	}
	const node operator <<(const int x) const{
		return node((A<<x)&MAX,(B<<x)&MAX);
	}
	const node operator * (int x) const{
		if (x==0) return node();
		if (x==1) return *this;
		if (x==2) return node(0,A);
		if (x==3) return node(A,A^B);
		return node();
	}
} A[maxn],B[maxn],C[maxn];
void fwt(node *A,int len,int inv) { //
	int i,j,k;
	for (i=2; i<=len; i<<=1) {
		for (j=0; j<len; j+=i) {
			for (k=j; k<j+i/2; k++) {
				auto a=A[k],b=A[k+i/2];
				if (inv==1) A[k+i/2]=a+b;
				else A[k+i/2]=b-a;
			}
		}
	}
}
char bit[maxn],ans[maxn];
int main() {
	int i,k;
	scanf("%d",&m); n=1<<m; MAX=n*2-1;
	REP(i,n) bit[i]=bit[i>>1]+(i&1);
	scanf("%s",str);
	REP(i,n) A[i].set(bit[i],str[i]-'0');
	scanf("%s",str);
	REP(i,n) B[i].set(bit[i],str[i]-'0');
	fwt(A,n,1),fwt(B,n,1);

	// REP(j,m+1) {REP(i,n) printf("%d ",A[i][j]);puts("");}
	// REP(j,m+1) {REP(i,n) printf("%d ",B[i][j]);puts("");}
	REP(k,n) REP(i,m+1)
		C[k]=C[k]+(A[k]<<i)*B[k][i];

	// REP(j,m+1) {REP(i,n) printf("%d ",C[i][j]);puts("");}
	
	fwt(C,n,-1);
	REP(i,n) ans[i]=C[i][bit[i]];
	REP(i,n) str[i]=(ans[i]&3)+'0';
	puts(str);
}
/*
*/