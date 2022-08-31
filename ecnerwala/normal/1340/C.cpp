#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<int> X(M);
	for (int i = 0; i < M; i++) {
		cin >> X[i];
	}
	sort(X.begin(), X.end());
	assert(X[0] == 0);
	assert(X[M-1] == N);

	int G, R; cin >> G >> R;
	vector<bool> vis(M * G);
	vis[0] = true;

	vector<int> islands; islands.reserve(M);
	islands.push_back(0);

	vector<int> q; q.reserve(M*G);

	int ans = -1;
	for (int T = 0; !islands.empty(); T++) {
		q.clear();
		for (int i : islands) {
			q.push_back(i*G);
		}
		islands.clear();

		for (int z = 0; z < int(q.size()); z++) {
			int cur = q[z];
			int i = cur / G;
			int t = cur % G;
			for (int j : {i-1, i+1}) {
				if (!(0 <= j && j < M)) continue;
				int nt = t + abs(X[i] - X[j]);
				if (nt > G) continue;

				if (j == M-1) {
					int cnd = T * (G+R) + nt;
					if (ans == -1 || cnd < ans) {
						ans = cnd;
					}
				}

				if (nt == G) {
					nt = 0;
				}

				if (vis[j*G + nt]) continue;
				vis[j*G+nt] = true;

				if (nt) {
					q.push_back(j*G+nt);
				} else {
					islands.push_back(j);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}