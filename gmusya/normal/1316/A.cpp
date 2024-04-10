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
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		int ans = min(sum, m);
		cout << ans << endl;
	}
	return 0;
}