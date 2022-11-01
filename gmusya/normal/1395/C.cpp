#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> a(n), b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int ans = 0; ans <= 511; ans++) {
		bool tf = true;
		for (int i = 0; i < n; i++) {
			bool tmp = false;
			for (int j = 0; j < m; j++)
				if (((a[i] & b[j]) | ans) == ans)
					tmp = true;
			if (!tmp) tf = false;
		}
		if (tf) {
			cout << ans;
			return 0;
		}
	}
	return 0;
}