#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a;
		while (n--) {
			int x; cin >> x;
			if (x == 1) a.push_back(1);
			else {
				while (a.back() != x - 1) a.pop_back();
				a.pop_back();
				a.push_back(x);
			}
			for (int i = 0; i != a.size(); ++i)
				cout << a[i] << ".\n"[i + 1 == a.size()];
		}
	}
	return 0;
}