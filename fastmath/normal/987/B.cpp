#include <bits/stdc++.h>

using namespace std;
#define int long long

map <int, int> d(int n) {
	map <int, int> ans;
 	for (int d = 2; d * d <= n; ++d) {
 		while (n % d == 0) {
 			++ans[d];
 		 	n /= d;
 		}
 	}
 	if (n != 1) ++ans[n];
 	return ans;
}
     	
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	map <int, int> da = d(a);
	map <int, int> db = d(b);

	for (pair <int, int> elem : da) {
	 	da[elem.first] *= b;
	}
	
	for (pair <int, int> elem : db) {
		db[elem.first] *= a;
	}

	if (da == db) {
		cout << "=\n";
	}
	else {
		if (log(a) * b < log(b) * a) {
		 	cout << "<\n";
		}
		else {
			cout << ">\n";
		}
	}

	return 0;
}