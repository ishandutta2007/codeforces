#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, a, b;
	cin >> k >> a >> b;
	int aa = a/k;
	int bb = b/k;
	if (aa == 0 && b % k != 0)
		cout << -1 << endl;
	else if (bb == 0 && a % k != 0)
		cout << -1 << endl;
	else if (aa == 0 && b == 0)
		cout << -1 << endl;
	else
		cout << aa + bb << endl;

	return 0;
}