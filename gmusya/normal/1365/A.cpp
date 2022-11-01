#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <vector <int>> a(n, vector <int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			int x = 1;
			for (int j = 0; j < m; j++)
				if (a[i][j])
					x = 0;
			cnt0 += x;
		}
		for (int j = 0; j < m; j++) {
			int x = 1;
			for (int i = 0; i < n; i++)
				if (a[i][j])
					x = 0;
			cnt1 += x;
		}
		int x = min(cnt0, cnt1);
		if (x % 2) cout << "Ashish\n";
		else cout << "Vivek\n";
	}
	return 0;
}