#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<pair<int, int>> d(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i - 1] = {a[i] - a[i - 1], i};
	}
	sort(d.begin(), d.end());
	for (int i = n - 1; i >= 0; i--) {
		printf("%d ", d[i].second);
	}
	puts("");
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