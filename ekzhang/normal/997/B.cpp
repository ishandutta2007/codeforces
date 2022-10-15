#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAX 5013
#define THRES 100
int N;
bool vis[2][MAX + 50];

LL solve(int N) {
	vis[0][0] = true;
	for (int k = 0; k < N; k++) {
		int b = k % 2;
		for (int i = 0; i < MAX; i++)
			vis[!b][i] = false;
		for (int i = MAX - 1; i >= 0; i--) {
			if (vis[b][i]) {
				vis[!b][i + 1] = true;
				vis[!b][i + 5] = true;
				vis[!b][i + 10] = true;
				vis[!b][i + 50] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < MAX; i++) {
		ans += vis[N%2][i];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	if (N <= THRES) {
		cout << solve(N) << endl;
	}
	else {
		LL ans = -12 - N;
		ans += (LL) 50LL * (N - 50);
		ans += solve(50);
		ans += 12 + 50;
		cout << ans << endl;
	}

	return 0;
}