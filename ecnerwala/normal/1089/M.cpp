#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10;

int N;
bool adj[MAXN][MAXN];

int scc[MAXN];
int outdeg[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
	for (int i = 0; i < N; i++) adj[i][i] = true;

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adj[i][k] && adj[k][j]) adj[i][j] = true;
			}
		}
	}

	vector<int> roots;
	for (int i = 0; i < N; i++) {
		for (int j = 0; true; j++) {
			if (adj[i][j] && adj[j][i]) {
				scc[i] = j;
				break;
			}
		}
		if (scc[i] == i) {
			roots.push_back(i);
		}

		outdeg[i] = 0;
		for (int j = 0; j < N; j++) {
			outdeg[i] += adj[i][j];
		}
	}

	// bigger outdeg is higher up
	sort(roots.begin(), roots.end(), [](int i, int j) { return outdeg[i] > outdeg[j]; });
	cout << 2 * N << ' ' << 3 << ' ' << 2 * int(roots.size()) + 1 << '\n';
	for (int r : roots) {
		for (int c = 0; c < N; c++) {
			cout << '.' << '#';
		}
		cout << '\n';
		for (int c = 0; c < N; c++) {
			if (adj[r][c]) cout << '.';
			else cout << '#';

			cout << '#';
		}
		cout << '\n';
		for (int c = 0; c < N; c++) {
			if (scc[c] == r) {
				cout << char('1' + c);
			} else {
				cout << '.';
			}

			// walk freely
			cout << '.';
		}
		cout << '\n';

		cout << '\n';

		for (int c = 0; c < N; c++) {
			if (scc[c] == r) {
				cout << '#';
			} else {
				cout << '.';
			}
			cout << '#';
		}
		cout << '\n';
		for (int z = 1; z < 3; z++) {
			for (int c = 0; c < N; c++) {
				cout << '#' << '#';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	// bottom pit
	for (int z = 0; z < 3; z++) {
		for (int c = 0; c < N; c++) {
			cout << '.' << '.';
		}
		cout << '\n';
	}

	return 0;
}