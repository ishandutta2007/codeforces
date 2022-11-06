#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, z;
	int mx = 0;
	cin >> n >> z;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		mx = max(mx, (v | z));
	}
	printf("%d\n", mx);
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