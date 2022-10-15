#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int y, b, r;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> y >> b >> r;
	int amt = min(min(r - 2, b - 1), y);

	cout << 3 * amt + 3 << endl;
	return 0;
}