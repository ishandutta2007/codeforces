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

const int maxN = 50 + 5;
const int INF = 0x3f3f3f3f;
int n, m, s, cnt[maxN];
vector<pii> G[maxN];
int f[maxN][maxN], d[maxN][maxN];
bitset<maxN> g, h;

void dfs(int u, int fa, int d[]) {
	for(auto p : G[u]) {
		int v = p.first, w = p.second;
		if(v == fa) continue;
		d[v] = d[u] + w;
		dfs(v, u, d);
	}
}

vector<int> lf;
int cntr;
void seek(int u, int fa) {
	if(G[u].size() == 1) lf.push_back(u);
	cntr += cnt[u];
	for(auto p : G[u]) if(p.first != fa) seek(p.first, u);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		G[x].emplace_back(y, z);
		G[y].emplace_back(x, z);
	}
	cin >> s >> m;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0; i < m; ++i) {
		int x; cin >> x; cnt[x]++;
		assert(x != s);
	}
	for(int u = 1; u <= n; ++u) {
		d[u][u] = 0;
		dfs(u, -1, d[u]);
	}
	memset(f, INF, sizeof(f));
	for(int u = 1; u <= n; ++u) if(G[u].size() == 1) f[0][u] = 0;
	for(int c = 1; c <= m; ++c) for(int u = 1; u <= n; ++u) if(G[u].size() == 1) {
		auto check = [&](int T) {
//			printf("check %d\n", T);
			g.reset(); g[0] = true;
//			memset(g, 0, sizeof(buc));
//			g[0] = true;
			for(int v = 1; v <= n; ++v) if(G[v].size() == 1) {
//				memset(h, 0, sizeof(buc));
				h.reset();
				for(int tc = 0; tc <= c; ++tc) if(f[c - tc][v] + d[u][v] >= T) {
//					for(int j = 0; j + tc <= c; ++j) h[j + tc] |= g[j];
					h |= g << tc;
				}
//				displaya(g, 1, n);
				swap(g, h);
			}
			return g[c];
		};
		int L = 0, R = n * 50 * 50;
		while(L < R) {
			int M = (L + R + 1) >> 1;
			if(check(M)) L = M;
			else R = M - 1;
		}
		f[c][u] = L;
//		eprintf("f(%d, %d) = %d\n", c, u, f[c][u]);
	}
	int ans = n * 50 * 50;
	for(auto p : G[s]) {
		lf.clear(); cntr = 0;
		seek(p.first, s);
		
		auto check = [&](int T) {
			g.reset(); g[0] = true;
			for(int v : lf) {
				h.reset();
				for(int tc = 0; tc <= cntr; ++tc) if(f[m - tc][v] + d[s][v] >= T) {
					h |= g << tc;
				}
				swap(g, h);
			}
			return g[cntr];
		};
		
		int L = 0, R = n * 50 * 50;
		while(L < R) {
			int M = (L + R + 1) >> 1;
			if(check(M)) L = M;
			else R = M - 1;
		}
		chmin(ans, L);
	}
	cout << ans << endl;
	return 0;
}