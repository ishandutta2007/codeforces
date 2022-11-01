#include <set>
#include <map>
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
typedef long long LL;
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPI;
const	int N = 100005;
const	int P = 1e9 + 7;
const	int inf = 1e9;
const	LL Inf = 1e15;

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
#else
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
}

template<typename T> inline void chkmin(T &a, const T &b) {if(a > b) a = b;}
template<typename T> inline void chkmax(T &a, const T &b) {if(a < b) a = b;}

int n,k;
int dp[1000005],g[1000005],fac[1000005],inv[1000005];

int main(){
#ifdef LOCAL
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d",&n,&k);
	fac[0]=1;
	REP(i,1,n) fac[i]=(LL)fac[i-1]*i%P;
	inv[0]=inv[1]=1;
	REP(i,2,n) inv[i]=(LL)inv[P%i]*(P-P/i)%P;
	REP(i,2,n) inv[i]=(LL)inv[i-1]*inv[i]%P;
	dp[1]=dp[0]=1;
	REP(i,2,k)dp[i]=(LL)dp[i-1]*i%P;
	REP(i,1,k)g[i]=(g[i-1]+(LL)inv[i]*dp[i])%P;
	REP(i,k+1,n){
		dp[i]=(g[i-1]+P-g[i-k-1])%P;
		dp[i]=(LL)dp[i]*fac[i-1]%P;
		g[i]=(g[i-1]+(LL)inv[i]*dp[i])%P;
	}

	int ans=0;
	REP(i,0,n-1) ans=(ans+(LL)dp[i]*fac[n-1]%P*inv[i])%P;
	ans=(0LL+fac[n]-ans)%P;
	ans=(ans+P)%P;
	printf("%d\n",ans);

	return 0;
}