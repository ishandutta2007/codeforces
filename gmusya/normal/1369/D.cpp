#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MAXN = 2e6;
const ll MOD = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	vector <ll> ans(MAXN + 1);
	for (int i = 3; i <= MAXN; i++) {
		ans[i] = 2 * ans[i - 2] + ans[i - 1];
		if (i % 3 == 0) ans[i] += 4;
		ans[i] %= MOD;
	}
	while (t--) {
		int x;
		cin >> x;
		cout << ans[x] << '\n';
	}
	return 0;
}