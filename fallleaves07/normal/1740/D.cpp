#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> p(k + 1), loc(k + 1);
	for (int i = 1; i <= k; i++) {
		cin >> p[i];
		loc[p[i]] = i;
	}
	int tot = 0, id = 0;
	bool ans = true;
	for (int i = k; i >= 1; i--) {
		if (loc[i] > id) {
			tot += loc[i] - id, id = loc[i];
			if (n * m - 2 - tot < 1) {
				ans = false;
			}
			--tot;
		} else {
			if (n * m - 2 - tot < 1) {
				ans = false;
			}
			--tot;
		}
	}
	puts(ans ? "YA" : "TIDAK");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}