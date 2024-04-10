#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int k, n;
	cin >> n >> k;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	if (cnt) {
		puts("YES");
	} else {
		puts("NO");
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