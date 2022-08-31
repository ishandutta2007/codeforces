#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	if (N <= 2) {
		cout << -1 << '\n';
		exit(0);
	}

	if (N >= 4) {
		vector<vector<int>> G(N, vector<int>(N));
		G[0][0] = 13; G[0][1] = 8; G[0][2] = 16; G[0][3] = 2;
		G[1][0] = 14; G[1][1] = 1; G[1][2] = 11; G[1][3] = 10;
		G[2][0] = 7; G[2][1] = 5; G[2][2] = 9; G[2][3] = 15;
		G[3][0] = 4; G[3][1] = 3; G[3][2] = 6; G[3][3] = 12;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				G[i][j] += N*N - 16;
			}
		}

		int idx = 0;
		for (int i = 4; i < N; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < i; j++) {
					G[i][j] = ++idx;
				}
				for (int j = i; j >= 0; j--) {
					G[j][i] = ++idx;
				}

				if (i == N-1) {
					swap(G[0][i], G[1][i]);
				}
			} else {
				for (int j = 0; j < i; j++) {
					G[j][i] = ++idx;
				}
				for (int j = i; j >= 0; j--) {
					G[i][j] = ++idx;
				}
				if (i == N-1) {
					swap(G[i][0], G[i][1]);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << G[i][j] << " ";
			}
			cout << '\n';
		}

		exit(0);
	}

	assert(N == 3);
	vector<int> cnd(9);
	iota(cnd.begin(), cnd.end(), 1);

	vector<vector<int>> queenAdj(9);
	vector<vector<int>> rookAdj(9);
	for (int x1 = 0; x1 < 3; x1++) {
		for (int y1 = 0; y1 < 3; y1++) {
			for (int x2 = 0; x2 < 3; x2++) {
				for (int y2 = 0; y2 < 3; y2++) {
					if (x1 == x2 || y1 == y2) {
						rookAdj[x1*3+y1].push_back(x2*3+y2);
					}
					if (x1 == x2 || y1 == y2 || x1-y1 == x2-y2 || x1+y1 == x2+y2) {
						queenAdj[x1*3+y1].push_back(x2*3+y2);
					}
				}
			}
		}
	}

	vector<int> range9(9); iota(range9.begin(), range9.end(), 0);

	auto simulate = [&](vector<int> nums, vector<vector<int>> adj) -> int {
		int ans = 0;
		vector<int> vis(9);
		int cur = int(find(nums.begin(), nums.end(), 1) - nums.begin());
		for (int z = 0; z+1 < 9; z++) {
			assert(!vis[cur]);
			vis[cur] = true;
			int nxt = *min_element(adj[cur].begin(), adj[cur].end(), [&](int a, int b) { return tie(vis[a], nums[a]) < tie(vis[b], nums[b]); });
			if (vis[nxt]) {
				nxt = *min_element(range9.begin(), range9.end(), [&](int a, int b) { return tie(vis[a], nums[a]) < tie(vis[b], nums[b]); });
				ans++;
			}
			cur = nxt;
		}
		return ans;
	};

	do {
		if (simulate(cnd, queenAdj) > simulate(cnd, rookAdj)) {
			cout << cnd[0] << ' ' << cnd[1] << ' ' << cnd[2] << '\n';
			cout << cnd[3] << ' ' << cnd[4] << ' ' << cnd[5] << '\n';
			cout << cnd[6] << ' ' << cnd[7] << ' ' << cnd[8] << '\n';
			exit(0);
		}
	} while (next_permutation(cnd.begin(), cnd.end()));
	cout << -1 << '\n';
	exit(0);

	return 0;
}