#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	a /= b;
	if (a % 2) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}