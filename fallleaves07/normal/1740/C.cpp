#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i + 1 < n - 1; i++){
		ans = max(ans, abs(a[i] - a[n - 1]) + abs(a[i] - a[i + 1]));
	}
	reverse(a.begin(), a.end());
	for (int i = 0; i + 1 < n - 1; i++){
		ans = max(ans, abs(a[i] - a[n - 1]) + abs(a[i] - a[i + 1]));
	}
	printf("%d\n", ans);
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