// July 26, 2018
// http://codeforces.com/contest/1011/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	int n, k;
	cin >> n >> k;
	int g = k;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		g = gcd(g, t);
	}

	cout << k / g << '\n';
	for (int i = 0; i < k; i += g) {
		cout << i << ' ';
	}
	cout << '\n';


	return 0;
}