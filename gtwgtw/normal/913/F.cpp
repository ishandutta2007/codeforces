#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define REP(i, x, y) for(int i = (int)x; i <= (int)y; i ++)
#define FOR(i, x, y) for(int i = (int)x; i <  (int)y; i ++)
#define PER(i, x, y) for(int i = (int)x; i >= (int)y; i --)
#define trace(x) cerr << #x << " " << x << endl;
#define dprintf(...) fprintf(stderr, __VA__ARGS__)
#define dln()        fprintf(stderr, "\n")
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<PII> VPI;
typedef vector<long long> VL;
const	int N = 100005;
const	int P = 998244353;
const	int inf = 1e9;
const	LL Inf = 1e18;

inline int IN(){
	char ch = getchar(); int x = 0, f = 0;
	while(ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - 48;
		ch = getchar();
	}
	return f ? (-x) : x;
}

inline int Pow(int x, int y, int p){
	int an = 1;
	for(; y; y >>= 1, x = (LL)x * x % p) if(y & 1) an = (LL)an * x % p;
	return an;
}

void renew(int &x, int y){
	x += y;
	if(x < 0) x += P;
	else if(x >= P) x -= P;
}

void setIO(string a){
#ifndef LOCAL
	freopen((a + ".in").c_str(), "r", stdin);
	freopen((a + ".out").c_str(), "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int C[2005][2005],n,a,b,p,pw[2005],pwx[2005],g[2005],f[2005],h[2005],R[2005];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d%d",&n,&a,&b);p=(LL)a*Pow(b,P-2,P)%P;

	pw[0]=pwx[0]=1;
	REP(i,1,n) pw[i]=(LL)pw[i-1]*p%P;
	REP(i,1,n) pwx[i]=(LL)pwx[i-1]*(1+P-p)%P;
	REP(i,1,n) R[i]=((LL)i*(i-1)/2)%P;
	
	C[0][0]=1;
	C[1][0]=1;C[1][1]=1;
	REP(i,2,n){
		REP(j,0,i){
			C[i][j]=(LL)C[i-1][j]*pw[j]%P;
			if(j)C[i][j]=(C[i][j]+(LL)C[i-1][j-1]*pwx[i-j])%P;
		}
	}

	g[1]=1;
	REP(i,2,n){
		g[i]=1;
		FOR(j,1,i) g[i]=(g[i]+(LL)(P-g[j])*C[i][j])%P;
	}

	f[1]=0;

	REP(i,2,n){
		//f[i]=f[1]*g[1]*C[i][1]+f[2]*g[2]*C[i][2]
		int res=0;
		FOR(j,1,i) res=(res+(LL)(0LL+f[j]+h[i-j])*g[j]%P*C[i][j])%P;
		f[i]=(LL)(res+R[i])*Pow(1+P-g[i],P-2,P)%P;
		h[i]=((LL)f[i]*g[i]+res)%P;
	}

	printf("%d\n",f[n]);

	return 0;
}