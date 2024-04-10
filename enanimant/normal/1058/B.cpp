// September 23, 2018
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	int n, d, m;
	cin >> n >> d >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int s = x + y, t = abs(x - y);
		if (!(s < d || s > 2 * n - d || t > d)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}


	return 0;
}