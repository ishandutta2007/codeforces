#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef pair<int, int> pii;
#define MAXN 1013

int N, M;
int Q;
int V[MAXN][MAXN];
pair<int, int> righ[MAXN][MAXN];
pair<int, int> down[MAXN][MAXN];

void print_board() {
	pii x = {0, 0};
	for (int i = 0; i < N; i++) {
		x = down[x.first][x.second];
		pii y = x;
		for (int j = 0; j < M; j++) {
			y = righ[y.first][y.second];
			cout << V[y.first - 1][y.second - 1] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> V[i][j];
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j != M) righ[i][j] = {i, j + 1};
			else righ[i][j] = {-1, -1};
			if (i != N) down[i][j] = {i + 1, j};
			else down[i][j] = {-1, -1};
		}
	}

	for (int q = 0; q < Q; q++) {
		int a, b, c, d, h, w;
		cin >> a >> b >> c >> d >> h >> w;
		pii p1 = {0, 0}, p2 = {0, 0};
		for (int i = 0; i < a - 1; i++) {
			p1 = down[p1.first][p1.second];
		}
		for (int i = 0; i < b - 1; i++) {
			p1 = righ[p1.first][p1.second];
		}
		for (int i = 0; i < c - 1; i++) {
			p2 = down[p2.first][p2.second];
		}
		for (int i = 0; i < d - 1; i++) {
			p2 = righ[p2.first][p2.second];
		}
		pii q1 = p1, q2 = p2;
		for (int i = 0; i < h; i++) {
			q1 = down[q1.first][q1.second];
			q2 = down[q2.first][q2.second];
			swap(righ[q1.first][q1.second], righ[q2.first][q2.second]);
		}
		for (int i = 0; i < w; i++) {
			q1 = righ[q1.first][q1.second];
			q2 = righ[q2.first][q2.second];
			swap(down[q1.first][q1.second], down[q2.first][q2.second]);
		}
		q1 = p1, q2 = p2;
		for (int i = 0; i < w; i++) {
			q1 = righ[q1.first][q1.second];
			q2 = righ[q2.first][q2.second];
			swap(down[q1.first][q1.second], down[q2.first][q2.second]);
		}
		for (int i = 0; i < h; i++) {
			q1 = down[q1.first][q1.second];
			q2 = down[q2.first][q2.second];
			swap(righ[q1.first][q1.second], righ[q2.first][q2.second]);
		}
	}

	print_board();

	cout.flush();
	return 0;
}