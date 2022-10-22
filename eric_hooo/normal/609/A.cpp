#include <bits/stdc++.h>
using namespace std;
int main () {
	int n; cin >> n;
	int m; cin >> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} 
	sort(a.rbegin(), a.rend());
	int now = 0;
	while (m > 0) m -= a[now], now++;
	cout << now << endl;
	return 0;
}