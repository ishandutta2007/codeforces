#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		a = a % k;
		if (a == 0)
			a = k;
		res = gcd(res, a);
	}
	res = gcd(res, k);
	vector<int> ans;
	if (k % res == 0)
		ans.push_back(0);
	for (int i = 1; i < k; ++i) {
		if (i % res == 0)
			ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}