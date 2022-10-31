#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 5005;
const int INF = 1e9 + 7;

int d[N][N], used[N];
int q[N], qs, qe;
vector<int> g[N];

void bfs(int s, int n) {
	forn(i, n) {
		d[s][i] = INF;
		used[i] = 0;
	}
	d[s][s] = 0;
	used[s] = 1;
	qs = qe = 0;
	q[qe++] = s;
	while(qs < qe) {
		int v = q[qs++];
		for(int to : g[v]) {
			if (!used[to]) {
				d[s][to] = d[s][v] + 1;
				q[qe++] = to;
				used[to] = 1;
			}
		}
	}
//	cerr << qe << '\n';
}

int curPos = -1;

void printBees(vector<int> &vs) {
	int win = 0;
	for(int v : vs) {
		cout << v + 1 << " ";
		if (v == curPos) {
			win = 1;
		}
	}
	cout << endl;
	if (win) exit(0);
	cin >> curPos;
	curPos--;
	for(int v : vs) {
		if (curPos == v) {
			exit(0);
		}
	}	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	forn(i, n) {
		bfs(i, n);
	}
//	cerr << "!\n";
	vector<int> vs;
	vs.pb(0);
	vs.pb(1);
	vs.pb(2);
/*	forn(t, 3) {
		int best = INF;
		int bestV = -1;
		forn(v, n) {
			int local = 0;
			forn(i, n) {
				int closest = d[i][v];
				for(int u : vs) {
					closest = min(closest, d[i][u]);
				}
				local = max(local, closest);
			}
			if (local < best) {
				best = local;
				bestV = v;
			}
		}
		vs.pb(bestV);
	}*/
	forn(i, n) {
		printBees(vs);
	
		vector<int> us;
		for(int to : g[curPos]) us.pb(to);
		
		int bestMax = INF, bestDiff = 0, bestSum = INF;
		int bestv0, bestv1, bestv2;
		
		for(int v : vs) g[v].pb(v);

		int win = 0;
		forn(i0, sz(g[vs[0]])) {
			int v0 = g[vs[0]][i0];
			forn(i1, sz(g[vs[1]])) {
				int v1 = g[vs[1]][i1];
				forn(i2, sz(g[vs[2]])) {
					int v2 = g[vs[2]][i2];
					
					if (v0 == curPos || v1 == curPos || v2 == curPos) {
						win = 1;
						bestv0 = v0;
						bestv1 = v1;
						bestv2 = v2;
						break;
					}
					
					int mx = 0, sum = 0;
					for(int u : us) {
						sum += d[u][v0] + d[u][v1] + d[u][v2];
						mx = max(min({
							d[u][v0],
							d[u][v1],
							d[u][v2]
						}), mx);
					}
					int diff = 1 + (v0 != v1) + (v2 != v1 && v2 != v0);
//					if (mx < bestMax || (mx == bestMax && diff > bestDiff)) {
					if (mx < bestMax || (mx == bestMax && sum < bestSum)) {
						bestMax = mx;
						bestDiff = diff;
						bestSum = sum;
						bestv0 = v0;
						bestv1 = v1;
						bestv2 = v2;
					}
				}
				if (win) break;
			}
			if (win) break;
		}
		
		for(int v : vs) g[v].pop_back();
		
		vs.clear();
		vs.pb(bestv0);
		vs.pb(bestv1);
		vs.pb(bestv2);
	}
	assert(0);
    return 0;
}