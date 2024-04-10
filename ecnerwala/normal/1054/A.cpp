#include<bits/stdc++.h>
using namespace std;

int main() {
	int x, y, z, t1, t2, t3; cin >> x >> y >> z >> t1 >> t2 >> t3;

	int elev = t3 + t3 + (abs(x-z) + abs(x-y)) * t2 + t3;
	int star = abs(x-y) * t1;

	if (elev <= star) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}