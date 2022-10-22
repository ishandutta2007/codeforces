#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int a[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	vector<bool> vis(n+1);
	vis[0] = true;
	for (int i = n; i > 0; i--) {
		if (!vis[i]) {
			for (int j = i; !vis[j]; j = a[j]) {
				vis[j] = true;
			}
			ans++;
		}
	}
	cout << ans << nl;

	return 0;
}