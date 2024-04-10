#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e5+1;
int low[N], vis[N], scomp[N], scompNum, I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
	for (int v : adj[u]) {
		if (!vis[v]) scc(v);
		if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
	if (vis[u] <= low[u]) { int v;
		do { v=verts.top(); verts.pop(); scomp[v] = scompNum; } while (v != u);
		++ scompNum;
	}
}
void get_scc(int n) { memset(vis, 0, sizeof vis); memset(scomp, -1, sizeof scomp);
	scompNum = I = 0; for (int i = 1; i <= n; i++) if (!vis[i]) scc(i); 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, m, h;
	cin >> n >> m >> h;

	int vals[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if ((vals[a]+1)%h == vals[b]) {
			adj[a].push_back(b);
		}
		if ((vals[b]+1)%h == vals[a]) {
			adj[b].push_back(a);
		}
	}

	get_scc(n);
	vector<int> res[scompNum];
	for (int i = 1; i <= n; i++) {
		res[scomp[i]].push_back(i);
	}

	int best = INF;
	int ans = -1;

	for (int i = 0; i < scompNum; i++) {
		if (res[i].size() < best) {
			bool bad = false;
			for (int v : res[i]) {
				for (int x : adj[v]) {
					if (scomp[x] != i) {
						bad = true;
						break;
					}
				}
				if (bad) break;
			}
			if (!bad) {
				ans = i;
				best = res[i].size();
			}
		}
	}

	cout << best << nl;
	for (int it : res[ans]) cout << it << " ";
	cout << nl;

	return 0;
}