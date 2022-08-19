#include<bits/stdc++.h>
using namespace std;

const int MAXN = 70;
const int MAXM = 70;
int N, M;
char G[MAXN][MAXM];

int go() {
	bool hasA = false, hasP = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (G[i][j] == 'P') hasP = true;
			else if (G[i][j] == 'A') hasA = true;
			else assert(false);
		}
	}
	if (!hasA) return -1;

	if (!hasP) return 0;
	{
		bool done = true;
		for (int i = 0; i < N; i++) {
			done = done && (G[i][0] == 'A');
		}
		if (done) return 1;
	}
	{
		bool done = true;
		for (int i = 0; i < N; i++) {
			done = done && (G[i][M-1] == 'A');
		}
		if (done) return 1;
	}
	{
		bool done = true;
		for (int j = 0; j < M; j++) {
			done = done && (G[0][j] == 'A');
		}
		if (done) return 1;
	}
	{
		bool done = true;
		for (int j = 0; j < M; j++) {
			done = done && (G[N-1][j] == 'A');
		}
		if (done) return 1;
	}

	// if any of the corners, return 2
	if (G[0][0] == 'A' || G[0][M-1] == 'A' || G[N-1][0] == 'A' || G[N-1][M-1] == 'A') return 2;
	for (int i = 0; i < N; i++) {
		bool done = true;
		for (int j = 0; j < M; j++) {
			done = done && (G[i][j] == 'A');
		}
		if (done) return 2;
	}

	for (int j = 0; j < M; j++) {
		bool done = true;
		for (int i = 0; i < N; i++) {
			done = done && (G[i][j] == 'A');
		}
		if (done) return 2;
	}

	// if any of the edges, return 3
	for (int i = 0; i < N; i++) {
		if (G[i][0] == 'A' || G[i][M-1] == 'A') return 3;
	}
	for (int j = 0; j < M; j++) {
		if (G[0][j] == 'A' || G[N-1][j] == 'A') return 3;
	}

	// otherwise at least 4
	return 4;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> G[i];
		}
		int ans = go();
		if (ans < 0) cout << "MORTAL" << '\n';
		else cout << ans << '\n';
	}

	return 0;
}