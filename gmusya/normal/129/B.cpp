#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <pair <int, int>> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].first--;
		a[i].second--;
	}
	vector <int> deg(n);
	for (int i = 0; i < m; i++) {
		deg[a[i].first]++;
		deg[a[i].second]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		vector <int> kek;
		for (int j = 0; j < n; j++)
			if (deg[j] == 1)
				kek.push_back(j);
		for (int j = 0; j < kek.size(); j++) 
			for (int y = 0; y < m; y++) 
				if (a[y].first == kek[j] || a[y].second == kek[j]) {
					deg[a[y].first]--;
					deg[a[y].second]--;
				}
		if (kek.size() > 0)
			cnt++;
	}
	cout << cnt;
	return 0;
}