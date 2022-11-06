#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector card(n, vector<int>(k));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> card[i][j];
		}
	}
	map<LL, int> c1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			LL hs = 0;
			for (int f = 0; f < k; f++) {
				int p = (3 - (card[i][f] + card[j][f]) % 3) % 3;
				hs = hs * 3 + p;
			}
			++c1[hs];
		}
	}
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		LL hs = 0;
		for (int f = 0; f < k; f++) {
			hs = hs * 3 + card[i][f];
		}
		if (c1.count(hs)) {
			int d = c1[hs];
			ans += d * (d - 1ll) / 2;
		}
	}
	printf("%lld\n", ans);
    return 0;
}