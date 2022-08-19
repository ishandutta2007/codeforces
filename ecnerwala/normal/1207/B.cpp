#include<bits/stdc++.h>
using namespace std;

int G[200][200];
int F[200][200];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> G[i][j];
		}
	}

	vector<pair<int, int>> res;
	for (int i = 0; i+1 < N; i++) {
		for (int j = 0; j+1 < M; j++) {
			if (G[i][j] && G[i+1][j] && G[i][j+1] && G[i+1][j+1]) {
				res.emplace_back(i+1, j+1);
				F[i][j] = F[i+1][j] = F[i][j+1] = F[i+1][j+1] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (F[i][j] != G[i][j]) {
				cout << -1 << '\n';
				exit(0);
			}
		}
	}

	cout << res.size() << '\n';
	for (auto it : res) cout << it.first << ' ' << it.second << '\n';
	return 0;
}