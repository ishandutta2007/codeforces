#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 800*2;
int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
    ++scompNum; }}
void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }
////////////////////////////////////////////////////////////////////////////////
// 2-SAT using SCC (previous version was TESTED F - SouthAmerica03)
////////////////////////////////////////////////////////////////////////////////
bool truth[N/2]; // N must be at least 2 times the number of variables
// the clause a || b becomes !a => b and !b => a in the implication graph
void add_clause(int a, int b) { adj[a^1].push_back(b); adj[b^1].push_back(a); }
bool two_sat(int n) { get_scc(n);
  for (int i = 0; i < n; i += 2) { if (scomp[i] == scomp[i^1]) return false;
    truth[i/2] = (scomp[i] < scomp[i^1]); } return true; }

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	int a[m], b[m];
	for (int i=0; i<m; i++) {
		cin >> a[i] >> b[i];
		if (a[i] > b[i]) swap(a[i], b[i]);
		for (int j=0; j<i; j++) {
			if ((a[i] < a[j] and a[j] < b[i] and b[i] < b[j])
				|| (a[j] < a[i] and a[i] < b[j] and b[j] < b[i])) {
				adj[2*i].push_back(2*j+1);
				adj[2*i+1].push_back(2*j);
				adj[2*j].push_back(2*i+1);
				adj[2*j+1].push_back(2*i);
			}
		}
	}

	if (two_sat(2*m)) {
		for (int i=0; i<m; i++) {
			cout << (char)(truth[i] ? 'i' : 'o');
		}
		cout << nl;
	}
	else {
		cout << "Impossible" << nl;
	}

	return 0;
}