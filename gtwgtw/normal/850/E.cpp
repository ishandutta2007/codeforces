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

int n, m;
char str[1 << 21];
int val[1 << 21], rev[1 << 21];
int gval[1 << 21];

void dft(int *a, int L, int R){
	if(L + 1 == R) return;
//	FOR(i, 0, 1 << n) if(i < rev[i]) swap(a[i], a[rev[i]]);
	int md = (L + R) / 2;
	dft(a, L, md);
	dft(a, md, R);
	FOR(i, L, md){
		int x = a[i], y = a[i - L + md];
		a[i] = (x + y) % P;
		a[i - L + md] = (x + P - y) % P;
	}
}

int ans = 0;
int clz[1 << 21];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%d", &n);
	m = 1 << n;
	scanf("%s", str + 1);

	FOR(i, 0, 1 << n) val[i] = str[i + 1] - '0', gval[i] = 1 - val[i];
	FOR(i, 1, 1 << n) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (n - 1));

	dft(val, 0, m);
	dft(gval, 0, m);
	FOR(i, 0, m) val[i] = (LL)val[i] * gval[i] % P;
	dft(val, 0, m);
	int rm = Pow(m, P - 2, P);
	FOR(i, 0, m) val[i] = (LL)val[i] * rm % P;

	FOR(i, 0, m) clz[i] = clz[i >> 1] + (i & 1);
	FOR(i, 0, m) val[i] = (LL)val[i] * (1 << clz[i]) % P;
	FOR(i, 0, m) ans = (ans + val[i]) % P;
	ans = (LL)ans * 3 % P;

	printf("%d\n", ans);


	return 0;
}