#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	if (a == b) cout << -1 << endl;
	else cout << max(a.size(), b.size()) << endl;
	return 0;
}