#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	bool tag = true;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 0 || a[i - 1] - x < 0) {
			a[i] = a[i - 1] + x;
		} else {
			a[i] = a[i - 1] - x;
			tag = false;
		}
	}
	if (!tag) {
		puts("-1");
	} else {
		for (int i = 1; i <= n; i++) {
			printf("%d%c", a[i], " \n"[i == n]);
		}
	}
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