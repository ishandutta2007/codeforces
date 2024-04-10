#include<bits/stdc++.h>
using namespace std;
using LL = long long;

bool solve() {
	int n, k;
	cin >> n >> k;
	vector<LL> s(n + 1), a(n + 1);
	for (int i = n - k + 1; i <= n; i++) {
		cin >> s[i];
	}
	if (k == 1) {
		return true;
	}
	for (int i = n - k + 2; i <= n; i++) {
		a[i] = s[i] - s[i - 1];
		if (i > n - k + 2 && a[i] < a[i - 1]) {
			return false;
		}
	}
	LL dmx = a[n - k + 2] * (n - k + 1ll);
	return dmx >= s[n - k + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		puts(solve() ? "Yes" : "No");
	}
    return 0;
}