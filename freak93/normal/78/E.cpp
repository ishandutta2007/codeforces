#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

class point {
	public:
	int x, y;
	point(): x(0), y(0) {}
	point(int _x, int _y): x(_x), y(_y) {}
	
	point operator+(point &alpha) const {
		return point(x + alpha.x, y + alpha.y);
	}
};

const int inf = 0x3f3f3f3f;

int men(char x) {
	if (x < '0' || x > '9')
		return 0;
	
	return x - '0';
}

bool okay(point x, int N) {
	if (x.x < 0 || x.y < 0 || x.x >= N || x.y >= N)
		return false;
	return true;
}

point dd[4] = {point(-1, 0), point(0, 1), point(1, 0), point(0, -1)};

vector< vector<int> > bfs(int T, vector< vector<int> > &matrix, point start) {

	queue<point> Q;
	Q.push(start);

	vector< vector<int> > dis(matrix.size(), vector<int>(matrix.size(), inf));
	dis[start.x][start.y] = 0;

	while (!Q.empty()) {
		point now = Q.front();
		Q.pop();

		if (dis[now.x][now.y] == matrix[now.x][now.y])
			continue;

		for (int i = 0; i < 4; ++i)
			if (okay(now + dd[i], matrix.size())) {
				int x = (now + dd[i]).x;
				int y = (now + dd[i]).y;
				if (dis[x][y] == inf && matrix[x][y] >= dis[now.x][now.y] + 1 && T > dis[now.x][now.y]) {
					Q.push(now + dd[i]);
					dis[x][y] = dis[now.x][now.y] + 1;
				}
			}
	}

	for (size_t i = 0; i < matrix.size(); ++i)
		for (size_t j = 0; j < matrix.size(); ++j)
			if (matrix[i][j] == -1)
				dis[i][j] = -1;
	return dis;
}

vector< vector<int> > get_matrix(vector<string> matrix) {
	vector< vector<int> > alpha(matrix.size(), vector<int>(matrix.size()));

	for (size_t i = 0; i < matrix.size(); ++i)
		for (size_t j = 0; j < matrix.size(); ++j)
			if (matrix[i][j] == 'Y')
				alpha[i][j] = -1;
			else
				alpha[i][j] = inf;
	
	return alpha;
}

int bfs(int S, int D, vector< vector<int> > &E, vector< vector<int> > &cap) {
	
	queue<int> Q;
	Q.push(S);

	vector<int> A(E.size(), -1);
	
	A[S] = S;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		for (vector<int>::iterator it = E[x].begin(); it != E[x].end(); ++it)
			if (A[*it] == -1 && cap[x][*it] > 0)
				A[*it] = x, Q.push(*it);
	}

	if (A[D] == -1)
		return 0;
	
	int flow = inf;
	for (int i = D; i != S; i = A[i])
		flow = min(flow, cap[A[i]][i]);
	
	for (int i = D; i != S; i = A[i]) {
		cap[A[i]][i] -= flow;
		cap[i][A[i]] += flow;
	}

	return flow;
}

void afis(vector< vector<int> > &matrix) {
	int N = matrix.size();
	for (int i = 0; i < N; ++i, cerr << "\n")
		for (int j = 0; j < N; ++j)
			cerr << matrix[i][j] << " ";
	
	cerr << "\n";
}

int main() {
	int N, T; cin >> N >> T;
	
	vector<string> science(N);
	for (int i = 0; i < N; ++i)
		cin >> science[i];
	
	vector<string> capsule(N);
	for (int i = 0; i < N; ++i)
		cin >> capsule[i];
	
	point reactor;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (science[i][j] == 'Z') {
				reactor = point(i, j);
			}

	vector< vector<int> > matrix = get_matrix(capsule);
	
	vector< vector<int> > poison = bfs(inf, matrix, reactor);

	vector< vector<int> > E(2 * N * N + 2);
	vector< vector<int> > cap(2 * N * N + 2, vector<int>(2 * N * N + 2));

	for (int i = 0; i < N * N; ++i) {
		E[2 * N * N].push_back(i);
		E[i].push_back(2 * N * N);
		cap[2 * N * N][i] = men(science[i / N][i % N]);

		E[2 * N * N + 1].push_back(i + N * N);
		E[i + N * N].push_back(2 * N * N + 1);
		cap[i + N * N][2 * N *N + 1] = men(capsule[i / N][i % N]);
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			vector< vector<int> > save_spots = bfs(T, poison, point(i, j));
			for (int k = 0; k < N; ++k)
				for (int l = 0; l < N; ++l)
					if (save_spots[k][l] != inf) {
						E[i * N + j].push_back(N * N + k * N + l);
						E[N * N + k * N + l].push_back(i * N + j);
						cap[i * N + j][N * N + k * N + l] = inf;
					}
		}

	int S = 2 * N * N;
	int D = 2 * N * N + 1;

	int flow, aux;
	for (flow = 0; (aux = bfs(S, D, E, cap)); flow += aux);

	cout << flow << "\n";
};