#include <bits/stdc++.h>
using namespace std;

int vis[100010];
int prime[100010], tot;

void PreCalc(int N) {
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) prime[tot++] = i;
		for (int j = 0; j < tot && i * prime[j] <= N; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int main() {
	PreCalc(100000);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cout << prime[i] << " ";
		}
		cout << endl;
	}
	return 0;
}