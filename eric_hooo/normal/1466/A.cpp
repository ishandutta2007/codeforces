#include <bits/stdc++.h>
using namespace std;

vector <int> all;
int a[100];

int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		all.clear();
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				all.push_back(a[j] - a[i]);
			}
		}
		sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
		cout << all.size() << endl;
	}
	return 0;
}