// September 23, 2018
// http://codeforces.com/contest/1058/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int n;
int a[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	cin >> n;
	string s;
	cin >> s;
	int sum = 0;
	bool all_zero = true;
	for (int i = 0; i < n; i++) {
		a[i] = s[i] - '0';
		sum += a[i];
		all_zero &= (a[i] == 0);
	}

	if (all_zero) {
		cout << "YES\n";
		return 0;
	}

	for (int s = 1; s < sum; s++) {
		int cur = 0;
		for (int i = 0; i < n; i++) {
			cur += a[i];
			if (cur == s) cur = 0;
			else if (cur > s) break;
		}
		if (cur == 0) {
			cout << "YES\n";
//			cout << "sum of each segment: " << s << '\n';
			return 0;
		}
	}
	cout << "NO\n";



	return 0;
}