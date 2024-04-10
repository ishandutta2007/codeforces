#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 23
int N, M, L;
LL K;
LL A[MAXN][MAXN];
map<LL, int> paths[MAXN], rpaths[MAXN];

void go(int i, int j, LL k=0) {
	if (i >= N || j >= M)
		return;
	if (i + j == L) {
		++paths[i][k];
		return;
	}
	go(i + 1, j, k ^ A[i][j]);
	go(i, j + 1, k ^ A[i][j]);
}

void rgo(int i, int j, LL k=0) {
	if (i < 0 || j < 0)
		return;
	if (i + j == L) {
		++rpaths[i][k];
		return;
	}
	rgo(i - 1, j, k ^ A[i][j]);
	rgo(i, j - 1, k ^ A[i][j]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	L = (N + M) / 2 - 1;
	go(0, 0);
	rgo(N-1, M-1);

	LL ans = 0;
	for (int i = 0; i < N; i++) {
		int j = L - i;
		for (auto p : paths[i]) {
			LL x = rpaths[i][p.first ^ K ^ A[i][j]];
			ans += x * p.second;
		}
	}

	cout << ans << endl;
	return 0;
}