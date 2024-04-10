#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#ifdef DEBUG
#define display(x) cerr << #x << " = " << (x) << endl;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == (st)) cerr << ((a)[qwq]);\
		else cerr << ", " << ((a)[qwq]);\
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

const int maxN = 200000 + 5;
int n, m;
vector<int> G[maxN], H[maxN];
bool vis[maxN], ins[maxN];
int g[maxN], h[maxN], cg[maxN], ch[maxN];

bool dfs(int u) {
	ins[u] = true;
	vis[u] = true;
	for(int v : G[u]) {
		if(!vis[v]) {
			if(!dfs(v)) return false;
		} else {
			if(ins[v]) return false;
		}
	}
	ins[u] = false;
	return true;
}
char s[maxN];

void topo(int g[], int cg[], vector<int> G[]) {
	queue<int> Q;
	for(int u = 1; u <= n; ++u) g[u] = u;
	for(int u = 1; u <= n; ++u) if(cg[u] == 0) Q.push(u);
	while(Q.size()) {
		int u = Q.front(); Q.pop();
		for(int v : G[u]) {
			chmin(g[v], g[u]);
			if(--cg[v] == 0) Q.push(v);
		}
	}
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#endif
	cin >> n >> m;
	memset(cg, 0, sizeof(cg));
	memset(ch, 0, sizeof(ch));
	for(int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		cg[y]++;
		H[y].push_back(x);
		ch[x]++;
	}
	memset(vis, 0, sizeof(vis));
	memset(ins, 0, sizeof(ins));
	for(int i = 1; i <= n; ++i) if(!vis[i]) {
		if(!dfs(i)) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	topo(g, cg, G);
	topo(h, ch, H);
	
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(g[i] == i && h[i] == i) s[i] = 'A', ans++;
		else s[i] = 'E';
	}
	s[n + 1] = 0;
	cout << ans << endl;
	cout << (s + 1) << endl;
	return 0;
}