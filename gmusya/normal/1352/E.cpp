#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		vector <int> pre(n + 1);
		for (int i = 1; i <= n; i++) 
			pre[i] = pre[i - 1] + a[i];
		vector <bool> tf(n + 1);
		for (int i = 0; i <= n; i++)
			for (int j = i + 2; j <= n; j++)
				if (pre[j] - pre[i] <= n)
					tf[pre[j] - pre[i]] = true;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += tf[a[i]];
		cout << ans << '\n';
	}
	return 0;
}