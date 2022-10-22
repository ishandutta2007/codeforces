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

#define R 0
#define K 1
#define B 2

struct Edge {
	int id, type, dist, rep, cv;
	Edge(){}
	Edge(int i, int t, int d=0, int r=0, int v=1):
		id(i), type(t), dist(d), rep(r), cv(v) {}
	bool operator < (const Edge& o) const {
		if (dist == o.dist) return rep > o.rep;
		else return dist > o.dist;
	}
};

const int N = 10;
vector<Edge> adj[N*N+1][3];
pii dist[N*N+1][N*N+1][3];
int grid[N][N];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n;
	cin >> n;

	auto get = [&](int i, int j) {
		return i*n+j;
	};
	auto val = [&](int v) {
		int i = v/n;
		int j = v%n;
		return grid[i][j];
	};

	int start = -1;
	int end = -1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) start = get(i,j);
			if (grid[i][j] == n*n) end = get(i,j);
		}
	}
	assert(start != -1);

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int ii=0; ii<n; ii++) {
				for (int jj=0; jj<n; jj++) {
					int di = abs(ii-i);
					int dj = abs(jj-j);
					int u = get(i,j);
					int v = get(ii,jj);
					if (ii==i&&jj==j) {
						for (int s=0; s<3; s++) {
							for (int t=0; t<3; t++) {
								if (s==t) continue;
								adj[u][s].push_back(Edge(v,t,1,1));
							}
						}
					} else {
						if (!di||!dj) {
							adj[u][R].push_back(Edge(v,R,1));
						}
						if ((di==1&&dj==2)||(di==2&&dj==1)) {
							adj[u][K].push_back(Edge(v,K,1));
						}
						if (di==dj) {
							adj[u][B].push_back(Edge(v,B,1));
						}
					}
				}
			}
		}
	}

	memset(dist,INF,sizeof dist);
	priority_queue<Edge> bfs;
	bfs.push(Edge(start,R));
	bfs.push(Edge(start,K));
	bfs.push(Edge(start,B));

	while (!bfs.empty()) {
		Edge cur = bfs.top();
		bfs.pop();

		//cerr << "vis " << cur.cv << " " << cur.id << " " << cur.type << nl;
		pii cdist = pii(cur.dist, cur.rep);
		if (cdist < dist[cur.cv][cur.id][cur.type]) {
			dist[cur.cv][cur.id][cur.type] = cdist;
			if (cur.cv == n*n && cur.id == end) break;
			for (const Edge& e : adj[cur.id][cur.type]) {
				bfs.push(Edge(e.id, e.type, cur.dist+e.dist, cur.rep+e.rep, cur.cv+(val(e.id)==cur.cv+1)));
			}
		}
	}

	pii ans = pii(INF,INF);
	for (int i=0; i<3; i++) {
		ans = min(ans, dist[n*n][end][i]);
	}
	cout << ans.first << " " << ans.second << nl;

	return 0;
}