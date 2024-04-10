#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1100;
const int MAXM = 1100;
int N, M;
int G[MAXN][MAXM];
int ans[MAXN][MAXM];

bool solve() {
	for (int c = 0; c < 16; c++) {
		if (__builtin_popcount(c) != 2) continue;
		for (int i = 0; i < N; i++) {
			vector<int> cnds;
			int curC = ((i & 1) ? (15^c) : c);
			for (int v = 0; v < 4; v++) if (curC & (1 << v)) cnds.push_back(v+1);

			bool isGood = false;
			for (int z = 0; z < 2; z++, swap(cnds[0], cnds[1])) {
				bool matches = true;
				for (int j = 0; j < M; j++) {
					ans[i][j] = cnds[j & 1];
					if (G[i][j] && G[i][j] != cnds[j&1]) {
						matches = false;
					}
				}
				if (matches) { isGood = true; break; }
			}
			if (!isGood) {
				goto bad;
			}
		}
		return true;
bad:;
	}
	return false;
}

bool realSolve() {
	if (solve()) return true;
	for (int i = 0; i < max(N, M); i++) {
		for (int j = i+1; j < max(N, M); j++) {
			swap(G[i][j], G[j][i]);
		}
	}
	swap(N, M);
	if (solve()) {
		for (int i = 0; i < max(N, M); i++) {
			for (int j = i+1; j < max(N, M); j++) {
				swap(ans[i][j], ans[j][i]);
			}
		}
		swap(N, M);
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < M; j++) {
			G[i][j] = s[j] - '0';
		}
	}

	if (realSolve()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << ans[i][j];
			}
			cout << '\n';
		}
	} else {
		cout << 0 << '\n';
	}

	return 0;
}