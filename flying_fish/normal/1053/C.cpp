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
const LL maxn=3e5+7;
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

inline int lowbit(int x){return x&-x;}
int A[maxn],w[maxn];
ll sumw[maxn],sumaw[maxn];
inline void update(ll A[],int x,ll val){
	for (;x<=n;x+=lowbit(x)) A[x]+=val;
}
inline void update(int x,int val){
	update(sumw,x,val-w[x]);
	update(sumaw,x,M+(ll)(val-w[x])*A[x]%M);
	w[x]=val;
}
inline ll query(ll A[],int x){
	ll ret=0;
	for (;x;x-=lowbit(x)) ret+=A[x];
	return ret;
}
inline ll query(ll A[],int l,int r){
	// printf(" query: %d %d\n",l,r);
	return query(A,r)-query(A,l-1);
}
inline ll query(int l,int x,int r){
	ll ret=0;
	// printf("query: %d %d %d\n",l,x,r);
	ret+= query(sumw,l,x)%M*A[x]%M-query(sumaw,l,x)%M;
	ret+=-query(sumw,x,r)%M*A[x]%M+query(sumaw,x,r)%M;
	// printf("%d %d %d : %lld\n",l,x,r,ret);
	return ret;
}
int main() {
	int i,k;
	scanf("%d%d",&n,&q);
	FOR(i,1,n) scanf("%d",&A[i]),A[i]-=i;
	FOR(i,1,n) scanf("%d",&k),update(i,k);
	while (q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if (l<0) update(-l,r);
		else {
			int L=l,R=r; r++;
			while (l+1<r){
				int mid=(l+r)/2;
				if (query(sumw,L,mid-1)-query(sumw,mid,R)<0) l=mid;
				else r=mid;
			} printf("%I64d\n",(query(L,l,R)%M+M)%M);
		}
	}
}
/*
// sum_w-sum_w<0
3
1 2 7
*/