#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, b;
	cin >> n >> b;
	vector<int> a(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	puts(b <= a[0] ? "Bob" : "Alice");
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