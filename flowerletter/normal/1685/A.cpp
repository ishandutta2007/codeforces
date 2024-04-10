#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	int T;
	for(cin >> T; T; T --) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i ++) cin >> a[i];
		if(n & 1) {
			cout << "NO\n";
			continue;
		}
		sort(a.begin(), a.end());
		vector<int> b(n);
		// cout << "qwq\n";
		b[n - 1] = a[0];
		for(int i = 1; i < n / 2; i ++) b[i * 2 - 1] = a[i];
		for(int i = n / 2; i < n; i ++) b[(i - n / 2) * 2] = a[i];
		// cout << "qwq\n";
		int flag = 1;
		// for(auto u : b) cout << u << ' '; cout << '\n';
		for(int i = 1; i < n; i += 2) {
			flag &= (b[i] < b[(i + 1) % n]);
			flag &= (b[i] < b[(i - 1 + n) % n]);
		}
		if(flag) {
			cout << "YES\n";
			for(auto u : b) cout << u << ' '; cout << '\n';
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}