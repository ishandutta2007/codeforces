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
template<typename A, typename B>
ostream& operator << (ostream& out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}

const int maxN = 14;
int n;
int G[maxN];
int can[maxN][maxN][1 << maxN];
int f[1 << maxN], p[1 << maxN];

vector<pii> vp;
void print(int i, int j, int S) {
	if((G[i] >> j & 1) && S == 0) {
		vp.emplace_back(i, j);
		return;
	}
	
	for(int k = 0; k < n; ++k) if(S >> k & 1)
		if((G[k] >> j & 1) && can[i][j][S] == can[i][k][S ^ (1 << k)] + 1) {
			vp.emplace_back(k, j);
			print(i, k, S ^ (1 << k));
			return;
		}
}
void print(int S) {
	if(S == (1 << 0)) return;
	int T = p[S];
	for(int i = 0; i < n; ++i) if((S ^ T) >> i & 1)
		for(int j = 0; j < n; ++j) if((S ^ T) >> j & 1)
			if(f[S] == f[S ^ T] + can[i][j][T]) {
				print(i, j, T);
				print(S ^ T);
				return;
			}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	int m; cin >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		G[x] |= (1 << y);
		G[y] |= (1 << x);
	}
	memset(can, 0x3f, sizeof(can));
	memset(f, 0x3f, sizeof(f));
	memset(p, -1, sizeof(p));
	for(int u = 0; u < n; ++u)
		for(int v = 0; v < n; ++v) if(G[u] >> v & 1)
			can[u][v][0] = 1;
	for(int S = 0; S < (1 << n); ++S)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) if(i != j)
				for(int k = 0; k < n; ++k) if((G[j] >> k & 1) && (S >> k & 1) == 0 && !(S == 0 && k == i))
					chmin(can[i][k][S | (1 << j)], can[i][j][S] + 1);
	f[1 << 0] = 0;
	for(int S = 0; S < (1 << n); ++S) if(f[S] <= m) {
		int nS = ((1 << n) - 1) ^ S;
		for(int i = 0; i < n; ++i) if(S >> i & 1)
			for(int j = 0; j < n; ++j) if(S >> j & 1)
				for(int T = nS; T; T = (T - 1) & nS) if(can[i][j][T] <= m)
					if(chmin(f[S | T], f[S] + can[i][j][T]))
						p[S | T] = T;
	}
	print((1 << n) - 1);
	cout << vp.size() << endl;
	for(auto p : vp) cout << (p.first + 1) << ' ' << (p.second + 1) << '\n';
	return 0;
}