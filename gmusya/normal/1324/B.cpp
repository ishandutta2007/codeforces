#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		vector <bool> used(5001);
		bool tf = false;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		for (int i = 2; i < n; i++) {
			used[a[i - 2]] = true;
			if (used[a[i]]) tf = true;
		}
		if (tf) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}