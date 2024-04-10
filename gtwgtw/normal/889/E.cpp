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
const	int N = 200005;
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

int n;
LL a[N];

inline int cmp(const LL &a,const LL &b){
	return a>b;
}

map<pair<int,LL>,LL>mps;
LL dp(int x,LL v){
	if(x>=n) return v*n;
	if(v==0) return 0;
	if(mps.count(mk(x,v)))return mps[mk(x,v)];
	x++;
	if(v>=a[x]){
		LL now=v%a[x];
		LL &res=mps[mk(x-1,v)]; res = 0;
		res=max(res,dp(x,now)+(v-now)*(x-1));
		res=max(res,dp(x,a[x]-1)+(v-now-a[x])*(x-1));
		return res;
	}else{
		int nxt=lower_bound(a+x,a+n+1,v,cmp)-a;
		if(nxt>n) return v*n;
		LL now=v%a[nxt];
		LL &res=mps[mk(x-1,v)]; res = 0;
		res=max(res,dp(nxt,now)+(v-now)*(nxt-1));
		res=max(res,dp(nxt,a[nxt]-1)+(v-now-a[nxt])*(nxt-1));
		return res;		
	}
}

int main(){
#ifdef LOCAL
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d",&n);
	REP(i,1,n) scanf("%lld",a+i);
	REP(i,2,n) a[i]=min(a[i],a[i-1]);

	printf("%lld\n",dp(1,a[1]-1));

	return 0;
}