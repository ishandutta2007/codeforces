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
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2) cnt1++;
			else cnt2++;
		}
		if (cnt1 && cnt2) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}