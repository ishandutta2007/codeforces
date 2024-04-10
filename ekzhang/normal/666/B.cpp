#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef pair<int, int> pii;

#define MAXN 3000
#define MAXM 5000
int N, M;
pii edges[MAXM];
vector<int> adj[MAXN];
bool adjm[MAXN][MAXN];
int dist[MAXN][MAXN];
int aux[MAXN][3];
int aux2[MAXN][3];

void bfs(int s, int d=0) {
	dist[s][s] = 0;
	queue<pii> q;
	q.push(pii {s, 0});
	while (!q.empty()) {
		pii x = q.front();
		q.pop();
		int n = x.first;
		for (int m : adj[n]) {
			if (dist[s][m] == -1) {
				dist[s][m] = x.second + 1;
				q.push(pii {m, dist[s][m]});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	int idx = 0;
	int oldM = M;
	for (int i = 0; i < oldM; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (u == v || adjm[u][v]) {
			M--;
			continue;
		}
		edges[idx] = {u, v};
		adj[u].push_back(v);
		adjm[u][v] = true;
		idx++;
	}

	// run BFS; calc dists
	memset(dist, -1, sizeof dist);
	for (int i = 0; i < N; i++) {
		bfs(i);
	}

	// find 3 farthest cities from each
	// aux is x->other, aux2 is other->x
	for (int i = 0; i < N; i++) {
		aux[i][0] = i;
		aux[i][1] = i;
		aux[i][2] = i;
		for (int j = 0; j < N; j++) {
			if (dist[i][j] >= dist[i][aux[i][0]]) {
				aux[i][2] = aux[i][1];
				aux[i][1] = aux[i][0];
				aux[i][0] = j;
			}
			else if (dist[i][j] >= dist[i][aux[i][1]]) {
				aux[i][2] = aux[i][1];
				aux[i][1] = j;
			}
			else if (dist[i][j] >= dist[i][aux[i][2]]) {
				aux[i][2] = j;
			}
		}
		aux2[i][0] = i;
		aux2[i][1] = i;
		aux2[i][2] = i;
		for (int j = 0; j < N; j++) {
			if (dist[j][i] >= dist[aux2[i][0]][i]) {
				aux2[i][2] = aux2[i][1];
				aux2[i][1] = aux2[i][0];
				aux2[i][0] = j;
			}
			else if (dist[j][i] >= dist[aux2[i][1]][i]) {
				aux2[i][2] = aux2[i][1];
				aux2[i][1] = j;
			}
			else if (dist[j][i] >= dist[aux2[i][2]][i]) {
				aux2[i][2] = j;
			}
		}
	}

	int ans = 0;
	int ansa = -1;
	int ansb = -1;
	int ansc = -1;
	int ansd = -1;
	for (int b = 0; b < N; b++) {
		for (int c = 0; c < N; c++) {
			if (b == c || dist[b][c] == -1) continue;

			int ai = 0; // a = aux2[b][ai];
			int di = 0; // d = aux[c][di];
			if (aux2[b][ai] == c) ai++;
			if (aux[c][di] == b) di++;
			if (dist[aux2[b][ai]][b] <= 0) continue;
			if (dist[c][aux[c][di]] <= 0) continue;

			// error(b, c);

			// only conflict now is if a == d
			if (aux2[b][ai] != aux[c][di]) {
				// good
				int cans = dist[aux2[b][ai]][b] + dist[b][c] + dist[c][aux[c][di]];
				if (cans > ans) {
					ans = cans;
					ansa = aux2[b][ai];
					ansb = b;
					ansc = c;
					ansd = aux[c][di];
				}
			}
			else {
				// two cases, depending on who bails out
				int pai = ai, pdi = di;
				bool bad = false;
				ai++;
				if (aux2[b][ai] == c) ai++;
				if (aux[c][di] == b) di++;
				if (dist[aux2[b][ai]][b] <= 0) bad = true;
				if (dist[c][aux[c][di]] <= 0) bad = true;
				if (!bad) {
					int cans = dist[aux2[b][ai]][b] + dist[b][c] + dist[c][aux[c][di]];
					if (cans > ans) {
						ans = cans;
						ansa = aux2[b][ai];
						ansb = b;
						ansc = c;
						ansd = aux[c][di];
					}
				}
				ai = pai;
				di = pdi;
				bad = false;
				di++;
				if (aux2[b][ai] == c) ai++;
				if (aux[c][di] == b) di++;
				if (dist[aux2[b][ai]][b] <= 0) bad = true;
				if (dist[c][aux[c][di]] <= 0) bad = true;
				if (!bad) {
					int cans = dist[aux2[b][ai]][b] + dist[b][c] + dist[c][aux[c][di]];
					if (cans > ans) {
						ans = cans;
						ansa = aux2[b][ai];
						ansb = b;
						ansc = c;
						ansd = aux[c][di];
					}
				}
			}
		}
	}

	ansa++;ansb++;ansc++;ansd++;
	cout << ansa << ' ' << ansb << ' ' << ansc << ' ' << ansd << endl;
	return 0;
}