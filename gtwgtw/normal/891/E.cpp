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
const	int N = 5005;
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

int n,k,a[N],res=1,gtw;
int dp1[N],dp2[N];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d",&n,&k);
	REP(i,1,n) scanf("%d",a+i);
	REP(i,1,n) res=(LL)res*a[i]%P;
	gtw=Pow(n,k,P);

	dp2[0]=1;
	REP(i,1,n){
		memcpy(dp1,dp2,sizeof dp1);
		memset(dp2,0,sizeof dp2);
		REP(x,0,n) dp2[x]=(dp2[x]+(LL)dp1[x]*a[i])%P;
		REP(x,1,n) dp2[x]=(dp2[x]+(LL)(P-dp1[x-1]))%P;
	}

	
	int laj=1,ans=0;
	REP(x,0,n){
		if(x>k)break;
		int now=Pow(n,k-x,P);
		ans=(ans+(LL)now*laj%P*dp2[x])%P;
		laj=(LL)laj*(k-x)%P;
	}

	gtw=Pow(gtw,P-2,P);
	ans=(LL)ans*gtw%P;
	ans=(res+P-ans)%P;
	printf("%d\n",ans);


	return 0;
}