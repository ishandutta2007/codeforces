#include<bits/stdc++.h>
using namespace std;

const int MAXN = 40;
const int MAXM = 40;
int N, M;
char G[MAXN][MAXM];
char output[MAXN*2][MAXM*2];

int deg[MAXN][MAXM]; // track degrees for convenience

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, -1, 0, 1};

pair<int, int> cc[MAXN][MAXM]; // cc root
pair<int, int> par[MAXN][MAXM]; // cc parent
pair<int, int> mg[MAXN][MAXM]; // dsu merge
int depth[MAXN][MAXM];

bool vis[MAXN][MAXM]; // visited the black node

pair<int, int> prv[MAXN*2][MAXM*2];

void buildTree(int i, int j) {
	assert(G[i][j] == 'O');
	mg[i][j] = {i,j};
	for (int d = 0; d < 4; d++) {
		if (G[i+mx[d]][j+my[d]] == 'X') continue;
		if (output[2*i + mx[d]][2*j + my[d]] != 'E') continue;
		if (pair<int, int>(i+mx[d], j+my[d]) == par[i][j]) continue;
		par[i+mx[d]][j+my[d]] = {i,j};
		cc[i+mx[d]][j+my[d]] = cc[i][j];
		depth[i+mx[d]][j+my[d]] = depth[i][j] + 1;
		buildTree(i+mx[d], j+my[d]);
	}
}

void buildTree() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cc[i][j] = {0,0};
			par[i][j] = {0,0};
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (G[i][j] == 'X') continue;
			if (cc[i][j] == pair<int, int>(0,0)) {
				cc[i][j] = {i,j};
				depth[i][j] = 0;
				buildTree(i, j);
			}
		}
	}
}

pair<int, int> getMg(pair<int, int> a) {
	if (mg[a.first][a.second] == a) return a;
	return mg[a.first][a.second] = getMg(mg[a.first][a.second]);
}

pair<int, int> getMg(int i, int j) { return getMg(pair<int, int>(i,j)); }

bool solve() {
	int numBad = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i % 2 != j % 2) continue;
			if (i == 1 && j == 1) continue;
			if (G[i][j] == 'X') continue;
			numBad++;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			deg[i][j] = 0;
		}
	}

	for (int round = 0; round < 2 * numBad; round++) {
		buildTree();

		vector<pair<int, int>> edges;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				vis[i][j] = false;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i % 2 != j % 2) continue;
				if (i == 1 && j == 1) continue;
				if (G[i][j] == 'X') continue;
				assert(deg[i][j] <= 2);
				if (deg[i][j] == 2) continue;

				vis[i][j] = true;

				for (int d = 0; d < 4; d++) {
					if (G[i+mx[d]][j+my[d]] == 'X') continue;
					if (output[2*i + mx[d]][2*j + my[d]] == 'E') continue;
					prv[2*i + mx[d]][2*j + my[d]] = {0,0};
					edges.emplace_back(2*i + mx[d], 2 * j + my[d]);
				}
			}
		}

		vector<pair<int, int>> nedges;
		while (!edges.empty()) {
			for (auto it : edges) {
				int x = it.first, y = it.second;
				assert(output[x][y] != 'E');

				int i1 = x / 2, j1 = y / 2;
				int i2 = (x+1) / 2, j2 = (y+1) / 2;

				if (cc[i1][j1] != cc[i2][j2]) {
					// we're done
					while (x != 0 && y != 0) {
						// swap it
						if (output[x][y] == ' ') {
							deg[x/2][y/2] ++;
							deg[(x+1)/2][(y+1)/2] ++;
							output[x][y] = 'E';
						} else if (output[x][y] == 'E') {
							deg[x/2][y/2] --;
							deg[(x+1)/2][(y+1)/2] --;
							output[x][y] = ' ';
						} else assert(false);

						tie(x,y) = prv[x][y];
					}
					goto foundPath;
				}

				tie(i1,j1) = getMg(i1,j1);
				tie(i2,j2) = getMg(i2,j2);
				while (tie(i1,j1) != tie(i2,j2)) {
					if (depth[i1][j1] < depth[i2][j2]) {
						swap(i1,i2);
						swap(j1,j2);
					}
					assert(depth[i1][j1] >= depth[i2][j2]);
					assert(mg[i1][j1].first == i1 && mg[i1][j1].second == j1);
					int ei = i1 + par[i1][j1].first;
					int ej = j1 + par[i1][j1].second;
					mg[i1][j1] = par[i1][j1];
					tie(i1,j1) = getMg(i1,j1);

					prv[ei][ej] = {x, y};

					int ni = ei / 2, nj = ej / 2;
					if (ni % 2 != nj % 2) {
						ni = (ei+1) / 2, nj = (ej+1) / 2;
					}
					assert(!(ni == 1 && nj == 1));

					if (!vis[ni][nj]) {
						//cerr << "visit " << ni << ' ' << nj << '\n';
						assert(deg[ni][nj] == 2);
						vis[ni][nj] = true;
						for (int d = 0; d < 4; d++) {
							if (G[ni+mx[d]][nj+my[d]] == 'X') continue;
							if (output[2*ni + mx[d]][2*nj + my[d]] == 'E') continue;

							prv[2*ni + mx[d]][2*nj + my[d]] = {ei, ej};
							nedges.emplace_back(2*ni + mx[d], 2*nj + my[d]);
						}
					}
				}
			}

			swap(edges, nedges);
			nedges.clear();
		}

		return false;
foundPath:
		;
		/*
		cerr << "---" << '\n';
		for (int i = 2 * 1; i <= 2 * N; i++) {
			for (int j = 2 * 1; j <= 2 * M; j++) {
				cerr << output[i][j];
			}
			cerr << '\n';
		}
		cerr << "---" << '\n';
		cerr << '\n';
		*/
	}

	// now we have to finish off the tree
	buildTree();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (G[i][j] == 'X') continue;
			for (int d = 0; d < 4; d++) {
				if (G[i+mx[d]][j+my[d]] == 'X') continue;
				if (output[2*i+mx[d]][2*j+my[d]] == 'E') continue;
				if (cc[i][j] != cc[i+mx[d]][j+my[d]]) {
					output[2*i+mx[d]][2*j+my[d]] = 'E';
					buildTree();
				}
			}
		}
	}

	/*
	cerr << "---" << '\n';
	for (int i = 2 * 1; i <= 2 * N; i++) {
		for (int j = 2 * 1; j <= 2 * M; j++) {
			cerr << output[i][j];
		}
		cerr << '\n';
	}
	cerr << "---" << '\n';
	cerr << '\n';
	*/
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (G[i][j] == 'X') continue;
			assert(cc[i][j].first == 1);
			assert(cc[i][j].second == 1);
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int j = 1; j <= M; j++) {
			G[0][j] = G[N+1][j] = 'X';
		}
		for (int i = 1; i <= N; i++) {
			cin >> (G[i]+1);
			G[i][0] = G[i][M+1] = 'X';
		}

		for (int i = 0; i <= 2 * (N + 1); i++) {
			for (int j = 0; j <= 2 * (M + 1); j++) {
				output[i][j] = (i % 2 == 0 && j % 2 == 0) ? G[i/2][j/2] : ' ';
			}
		}

		if (solve()) {
			cout << "YES" << '\n';
			for (int i = 2 * 1; i <= 2 * N; i++) {
				output[i][2 * M + 1] = '\0';
				cout << (output[i] + 2) << '\n';
			}
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}