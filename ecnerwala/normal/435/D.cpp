#include<bits/stdc++.h>
using namespace std;

const int MAXN = 600;
const int MAXM = 600;
int N, M;
int G[MAXN][MAXM];

int ans = 0;

void transpose() {
	for (int i = 0; i < max(N, M); i++) {
		for (int j = i+1; j < max(N, M); j++) {
			swap(G[i][j], G[j][i]);
		}
	}
	swap(N, M);
}
void flipY() {
	for (int i = 0; i < N; i++) {
		reverse(G[i], G[i] + M);
	}
}
void flipX() {
	transpose();
	flipY();
	transpose();
}

int pref[MAXN][MAXM];
void solveRect() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pref[i][j] = (i-1 >= 0 && j+1 < M ? pref[i-1][j+1] : 0) + G[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (G[i][j]) continue;
			for (int k = 1; i+k < N && j+k < M; k++) {
				if (G[i][j+k] || G[i+k][j]) break;
				if (pref[i+k][j] == pref[i][j+k]) ans++;
			}
		}
	}
}

void solveDiag() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pref[i][j] = (i ? pref[i-1][j] : 0) + G[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (G[i][j]) continue;
			for (int k = 1; i-k >= 0 && i+k < N && j+k < M; k++) {
				if (G[i-k][j+k] || G[i+k][j+k]) break;
				if (pref[i-k][j+k] == pref[i+k][j+k]) ans++;
			}
		}
	}
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

	for (int fx = 0; fx < 2; fx++, flipX()) {
		for (int fy = 0; fy < 2; fy++, flipY()) {
			solveRect();
		}
	}

	for (int t = 0; t < 2; t++, transpose()) {
		for (int fy = 0; fy < 2; fy++, flipY()) {
			solveDiag();
		}
	}

	cout << ans << '\n';
	return 0;
}