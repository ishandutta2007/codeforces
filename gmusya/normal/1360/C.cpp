#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;  
	while (t--) {
		int n;
		cin >> n;
		vector <int> a, b;
		vector <bool> used(101);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			used[x] = true;
			if (x % 2) b.push_back(x);
			else a.push_back(x);
		}
		if (a.size() % 2 == 0) {
			cout << "YES\n";
			continue;
		}
		bool tf = false;
		for (int i = 1; i <= 99; i++)
			if (used[i] && used[i + 1])
				tf = true;
		if (tf) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}