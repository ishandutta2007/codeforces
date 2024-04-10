#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(int n) {
	set <int> ms;
	for (int a = 0; a <= n; ++a) {
	    for (int b = 0; a + b <= n; ++b) {
	     	for (int c = 0; a + b + c <= n; ++c) {
	     	 	int d = n - a - b - c;
				ms.insert(a + b * 5 + c * 10 + d * 50);
	     	}
	    }
	}	
	return ms.size();
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n;
	cin >> n;
	
	if (n < 20) {
		cout << get(n) << '\n';
		return 0;
	}

	cout << get(20) + 49 * (n - 20) << '\n';
 	return 0;
}