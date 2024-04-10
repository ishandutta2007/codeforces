#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	for (cin >> t; t; t -= 1) {
		string x1, x2;
		int p1, p2;
		cin >> x1 >> p1 >> x2 >> p2;
		int p = min(p1, p2);
		p1 -= p;
		p2 -= p;
		if (x1.size() + p1 != x2.size() + p2)
			cout << (x1.size() + p1 > x2.size() + p2 ? ">" : "<");
		else {
			x1 += string(p1, '0');
			x2 += string(p2, '0');
			if (x1 > x2) cout << ">";
			else if (x1 < x2) cout << "<";
			else cout << "=";
		}
		cout << "\n";
	}
	return 0;
}