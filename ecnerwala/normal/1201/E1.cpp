#include<bits/stdc++.h>
using namespace std;

const int mx[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
const int my[8] = {-2, -2, 2, 2, -1, -1, 1, 1};

const int MAXN = 1100;
const int MAXM = 1100;
int N, M;

const int MAXV = MAXN * MAXM;
int V;

int source[2];
int target[2];

int dist[2][MAXV];
int nxt[2][MAXV];

int st_dist[2][2];

bool parity(int v) {
	return ((v / M) + (v % M)) & 1;
}

bool one_move(int a, int b) {
	int dx = abs(a / M - b / M);
	int dy = abs(a % M - b % M);
	return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	V = N * M;
	{
		int X0, Y0, X1, Y1;
		cin >> X0 >> Y0 >> X1 >> Y1;
		X0--, Y0--, X1--, Y1--;
		source[0] = X0 * M + Y0;
		source[1] = X1 * M + Y1;
	}

	target[0] = (N/2-1) * M + (M/2-1);
	target[1] = (N/2+1-1) * M + (M/2-1);

	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < V; i++) dist[z][i] = -1;
		queue<int> q;
		dist[z][target[z]] = 0;
		q.push(target[z]);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			int x = cur / M, y = cur % M;
			for (int d = 0; d < 8; d++) {
				int nx = x + mx[d], ny = y + my[d];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					int n = nx * M + ny;
					if (dist[z][n] == -1) {
						dist[z][n] = dist[z][cur] + 1;
						nxt[z][n] = cur;
						q.push(n);
					}
				}
			}
		}
		for (int x = 0; x < 2; x++) {
			st_dist[x][z] = dist[z][source[x]];
		}
	}

	int adv;
	if (parity(source[0]) != parity(source[1])) {
		// player 0 has the parity advantage
		adv = 0;
	} else {
		adv = 1;
	}
	int dis_dist = st_dist[!adv][!adv];
	int adv_turns = (adv == 0) ? dis_dist : dis_dist - 1;

	int me, goal;
	if (st_dist[adv][adv] <= adv_turns) {
		me = adv;
		goal = adv;
	} else if (st_dist[adv][!adv] - 1 <= adv_turns) {
		me = adv;
		goal = !adv;
	} else {
		me = !adv;
		goal = !adv;
	}

	cout << (me == 0 ? "WHITE" : "BLACK") << '\n' << flush;
	int cur[2] = {source[0], source[1]};
	for (int t = 0; true; t++) {
		if (t % 2 == me) {
			auto print_pos = [&]() {
				cout << (cur[me] / M + 1) << ' ' << (cur[me] % M + 1) << '\n' << flush;
			};
			if (one_move(cur[me], cur[!me])) {
				// take it
				cur[me] = cur[!me];
				print_pos();
				exit(0);
			}

			if (cur[me] == target[goal]) goal = me;

			cur[me] = nxt[goal][cur[me]];
			print_pos();
			if (cur[me] == target[me]) {
				exit(0);
			}
		} else {
			int x, y; cin >> x >> y;
			if (x == -1 && y == -1) {
				exit(0); // WRONG ANSWER
			}
			x--, y--;
			cur[!me] = x * M + y;
		}
	}

	return 0;
}