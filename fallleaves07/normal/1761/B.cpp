#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> vals;
	for (int i = 0; i < n; i++) {
		cin >> a[i], vals.insert(a[i]);
	}
	if (n == 1) {
		printf("1\n");
		return;
	}
	if ((int)vals.size() >= 3) {
		printf("%d\n", n);
		return;
	}
	printf("%d\n", n / 2 + 1);
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