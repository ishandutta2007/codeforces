#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1000000;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector <int> a(n);
		vector <vector <int>> b(n + 1);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bool tf = true;
		for (int i = 0; i < n; i++) {
			b[a[i]].push_back(i);
		}
		int ans = INF;
		for (int i = 0; i < b.size(); i++) {
			if (b[i].size() > 0) 
				for (int j = 0; j < b[i].size() - 1; j++)
					ans = min(ans, b[i][j + 1] - b[i][j]);
		}
		if (ans == INF)
			cout << "-1" << endl;
		else
			cout << ans + 1 << endl;
	}
	return 0;
}