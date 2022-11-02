#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << x << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}
#define displayv(v) displaya(v, 0, (int)(v).size() - 1)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define display(x) ;
#define displaya(a, st, n) ;
#define displayv(v) ;
#define eprintf(...) if(0) fprintf(stderr, "...")
#endif
template<typename T> bool chmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<typename T> bool chmax(T &a, const T &b) { return a < b ? a = b, true : false; }

const int maxN = 2000 + 5;
const int P = 1000000007;
int n, m;
char b[maxN][maxN];
int suf[maxN][maxN], dow[maxN][maxN], h[maxN][maxN], g[maxN][maxN];
int ph[maxN][maxN], pg[maxN][maxN];

void inc(int &x, int y) { (x += y) >= P ? x -= P : 233; }
void dec(int &x, int y) { (x -= y) <  0 ? x += P : 233; }

int solve() {
	if(n == 1 && m == 1) return 1;
	memset(suf, 0, sizeof(suf));
	memset(dow, 0, sizeof(dow));
	for(int i = 1; i <= n; ++i) {
		suf[i][m + 1] = 0;
		for(int j = m; j >= 0; --j) suf[i][j] = suf[i][j + 1] + (b[i][j] == 'R');
	}
	for(int j = 1; j <= m; ++j) {
		dow[n + 1][j] = 0;
		for(int i = n; i >= 0; --i) dow[i][j] = dow[i + 1][j] + (b[i][j] == 'R');
	}
	memset(h, 0, sizeof(h));
	memset(g, 0, sizeof(g));
	
	h[1][1] = g[1][1] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(i > 1) { // solve h
				h[i][j] = g[i - 1][j];
				ph[i][j] = ph[i - 1][j];
				if(ph[i][j] == 0) ph[i][j] = 1;
				while(ph[i][j] < i && dow[ph[i][j] + 1][j] > n - i) ++ph[i][j];
				dec(h[i][j], g[ph[i][j] - 1][j]);
//				eprintf("h(%d, %d) = %d\n", i, j, h[i][j]);
			}
			inc(h[i][j], h[i][j - 1]);
			if(j > 1) { // solve g
				g[i][j] = h[i][j - 1];
				pg[i][j] = pg[i][j - 1];
				if(pg[i][j] == 0) pg[i][j] = 1;
				while(pg[i][j] < j && suf[i][pg[i][j] + 1] > m - j) ++pg[i][j];
				dec(g[i][j], h[i][pg[i][j] - 1]);
//				eprintf("g(%d, %d) = %d\n", i, j, g[i][j]);
			}
			inc(g[i][j], g[i - 1][j]);
		}
	}
	for(int i = n; i >= 1; --i)
		for(int j = m; j >= 1; --j)
			dec(h[i][j], h[i][j - 1]), dec(g[i][j], g[i - 1][j]);
	for(int i = 1; i <= n; ++i) displaya(h[i], 1, m);
	for(int i = 1; i <= n; ++i) displaya(g[i], 1, m);
	int i = n, j = m;
	LL ans = h[i][j] + g[i][j];
	return (ans % P + P) % P;
}

/*
5 7
....R..
...RR..
..RR...
..R....
....R..
*/

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m;
	memset(b, 0, sizeof(b));
	for(int i = 1; i <= n; ++i) cin >> (b[i] + 1);
	cout << solve() << endl;
#ifdef DEBUG
	for(int i = 1; i <= max(n, m); ++i)
		for(int j = i + 1; j <= max(n, m); ++j)
			swap(b[i][j], b[j][i]);
	swap(n, m);
	display(solve());
#endif
	return 0;
}