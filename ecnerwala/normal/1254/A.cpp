#include<bits/stdc++.h>
using namespace std;

void go() {
	int R, C, K; cin >> R >> C >> K;
	vector<string> G(R);
	for (int i = 0; i < R; i++) cin >> G[i];
	int rice = 0;
	for (int i = 0; i < R; i++) {
		if (i & 1) reverse(G[i].begin(), G[i].end());
		for (int j = 0; j < C; j++) {
			rice += G[i][j] == 'R';
		}
	}
	int cur = 0;
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cnt += G[i][j] == 'R';
			G[i][j] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[cur];
			int v = (rice / K) * (cur+1) + min(rice % K, cur+1);
			if (cnt >= v) {
				cur++;
				cur = min(cur, K-1);
			}
		}
	}
	for (int i = 0; i < R; i++) {
		if (i & 1) reverse(G[i].begin(), G[i].end());
		cout << G[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		go();
	}

	return 0;
}