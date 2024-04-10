#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111;
char win[N][N][2];

void solve() {
	int n = nxt();
	int cnt[2] = {0, 0};
	for (int i = 0; i < n; ++i) {
		cnt[abs(nxt()) % 2] += 1;
	}
	cout << (win[cnt[0]][cnt[1]][0] ? "Alice" : "Bob") << "\n";
}

int main() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int want : {0, 1}) {
				if (i == 0 && j == 0) {
					win[i][j][want] = want == 0;
					continue;
				}
				char& can = win[i][j][want] = false;
				if (i) {
					can |= !win[i - 1][j][(j + 1 + want) % 2];
				}
				if (j) {
					can |= !win[i][j - 1][(j + 1 + want) % 2];
				}
			}
		}
	}

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}