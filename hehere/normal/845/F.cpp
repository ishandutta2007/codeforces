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

const int maxN = 250 + 5;
const int maxM = 15;
const int P = 1000000007;
int n, m;
char b[maxN][maxN];
int f[2][2][2][1 << maxM];
// f(p, left, used, S)

void inc(int &x, const int &y) {
	(x += y) >= P ? x -= P : 233;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	memset(b, 0, sizeof(b));
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> b[i];
	if(n < m) {
		eprintf("flipped\n");
		for(int i = 0; i < m; ++i)
			for(int j = i + 1; j < m; ++j)
				swap(b[i][j], b[j][i]);
		swap(n, m);
	}
	memset(f, 0, sizeof(f));
	int p = 0;
	f[p][0][0][0] = 1;
	for(int i = 0; i < n; ++i) {
//		display(b[i]);
		for(int j = 0; j < m; ++j) {
//			eprintf("cell %d %d\n", i, j);
			p ^= 1;
			memset(f[p], 0, sizeof(f[p]));
			for(int lef = 0; lef < 2; ++lef)
				for(int u = 0; u < 2; ++u)
					for(int t = 0; t < (b[i][j] == '.' ? 2 : 1); ++t) {
						bool taken = (b[i][j] == 'x');
						taken |= lef;
						taken |= t;
						int nlef = b[i][j] == '.' ? (lef | t) : 0;
						for(int S = 0; S < (1 << m); ++S) if(f[p ^ 1][lef][u][S]) {
							int nS = S;
							bool tak = taken | !!(S >> j & 1);
							int nu = u + (int)!tak;
							if(b[i][j] == 'x') nS &= ~(1 << j);
							else if(t) nS |= (1 << j);
							if(nu <= 1) {
//								eprintf("%d %d %s -> %d %d %s with %d\n", lef, u, bitset<4>(S).to_string().c_str(),
//									nlef, nu, bitset<4>(nS).to_string().c_str(), f[p ^ 1][lef][u][S]);
								inc(f[p][nlef][nu][nS], f[p ^ 1][lef][u][S]);
							}
						}
					}
		}
		p ^= 1;
		memset(f[p], 0, sizeof(f[p]));
		for(int lef = 0; lef < 2; ++lef) for(int u = 0; u < 2; ++u) for(int S = 0; S < (1 << m); ++S)
			inc(f[p][0][u][S], f[p ^ 1][lef][u][S]);
	}
	
	
	LL ans = 0;
	for(int S = 0; S < (1 << m); ++S) ans += f[p][0][0][S] + f[p][0][1][S];
	cout << (ans % P) << endl;
	return 0;
}