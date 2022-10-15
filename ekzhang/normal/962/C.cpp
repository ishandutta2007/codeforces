#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

bool sq(int x) {
	int y = (int) sqrt(x);
	for (int z = y - 1; z <= y + 1; z++)
		if (z * z == x)
			return true;
	return false;
}

string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> S;
	int ans = -1;
	for (int mask = 1; mask < (1 << S.size()); mask++) {
		string K;
		for (int b = 0; b < S.size(); b++)
			if (mask & (1<<b))
				K += S[b];
		if (K[0] != '0' && sq(stoi(K)) && (ans == -1 || ans > S.size() - __builtin_popcount(mask)))
			ans = S.size() - __builtin_popcount(mask);
	}

	cout << ans << endl;
	return 0;
}