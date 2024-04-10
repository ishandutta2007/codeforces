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

int n, x, y, a[2000005];
LL sm[2000005];
LL gsm[2000005];

int main(){
#ifdef LOCAL
	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	
	scanf("%d%d%d", &n, &x, &y);
	REP(i, 1, n){
		int x;
		scanf("%d", &x);
		a[x] ++;
	}
	int m = 2000000;
	REP(i, 1, m) sm[i] = sm[i - 1] + a[i];
	REP(i, 1, m) gsm[i] = gsm[i - 1] + (LL)a[i] * i;

	LL res = 1LL << 60;
	int t = x / y;
	REP(d, 2, m){
		LL ans = 0;
		for(int j = 0; j <= m; j += d){
			//y * t <= x
			//t <= x / y
			//[0, fen]
			//[fen + 1, d - 1]

			int tl1 = j + 1, tr1 = j + d - t - 1;
			int tl2 = j + d - t, tr2 = j + d - 1;
			tr1 = min(tr1, m);
			tr2 = min(tr2, m);
			tl1 = max(tl1, j + 1);
			tl2 = max(tl2, j + 1);
			if(tl1 <= tr1){
				ans += (LL)x * (sm[tr1] - sm[tl1 - 1]);
			}
			if(tl2 <= tr2){
				ans += (LL)y * ((j + d) * (sm[tr2] - sm[tl2 - 1]) - (gsm[tr2] - gsm[tl2 - 1]));
			}
		}
		res = min(res, ans);
	}
	cout << res << endl;

	return 0;
}