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

int n, q, p[N], rt[N];
int lc[N * 50], rc[N * 50], sm[N * 50], cnt;

void add(int &x, int L, int R, int p){
	++ cnt; lc[cnt] = lc[x], rc[cnt] = rc[x], sm[cnt] = sm[x] + 1, x = cnt;
	if(L == R) return;
	int md = (L + R) / 2;
	if(p <= md) add(lc[x], L, md, p);
	else add(rc[x], md + 1, R, p);
}

int pos;
int Ask(int x, int L, int R){
	if(L == R) return sm[x];
	int md = (L + R) / 2;
	if(pos <= md) return Ask(lc[x], L, md);
	else return sm[lc[x]] + Ask(rc[x], md + 1, R);
}

int ask(int x, int y){
	if(!y) return 0;
	pos = y;
	return Ask(rt[x], 1, n);	
}

int ask(int x, int yl, int yr){
	if(!x) return 0;
	return ask(x, yr) - ask(x, yl - 1);
}

int ask(int xl, int xr, int yl, int yr){
	return ask(xr, yl, yr) - ask(xl - 1, yl, yr);
}

LL C(LL x){return x * (x - 1) / 2;}

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif

	scanf("%d%d", &n, &q);
	REP(i, 1, n){
		int x;
		scanf("%d", &x);
		p[i] = x;
	}
	REP(i, 1, n){
		rt[i] = rt[i - 1];
		add(rt[i], 1, n, p[i]);
	}
	REP(i, 1, q){
		int xl, xr, yl, yr;
		scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
		LL ans = C(n);
		if(1 <= xl - 1){
			int ret = ask(1, xl - 1, 1, n);
			ans -= C(ret);
		}
		if(xr + 1 <= n){
			int ret = ask(xr + 1, n, 1, n);
			ans -= C(ret);
		}
		if(1 <= yl - 1){
			int ret = ask(1, n, 1, yl - 1);
			ans -= C(ret);
		}
		if(yr + 1 <= n){
			int ret = ask(1, n, yr + 1, n);
			ans -= C(ret);
		}
		if(1 <= xl - 1 && 1 <= yl - 1){
			int ret = ask(1, xl - 1, 1, yl - 1);
			ans += C(ret);
		}
		if(xr + 1 <= n && 1 <= yl - 1){
			int ret = ask(xr + 1, n, 1, yl - 1);
			ans += C(ret);
		}
		if(1 <= xl - 1 && yr + 1 <= n){
			int ret = ask(1, xl - 1, yr + 1, n);
			ans += C(ret);
		}
		if(xr + 1 <= n && yr + 1 <= n){
			int ret = ask(xr + 1, n, yr + 1, n);
			ans += C(ret);
		}
		printf("%lld\n", ans);
	}
	

	return 0;
}