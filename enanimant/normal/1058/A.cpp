// September 23, 2018
// http://codeforces.com/contest/1058/problem/A

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


	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		if (r) {
			cout << "HARD\n";
			return 0;
		}
	}
	cout << "EASY\n";


	return 0;
}