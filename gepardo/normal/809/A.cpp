#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int modulo = (int)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	static int powersOfTwo[400000] = {};
	powersOfTwo[0] = 1;
	for (int i = 1; i < 400000; i++) {
		powersOfTwo[i] = (powersOfTwo[i-1] * 2) % modulo;
	}
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += ((int64_t)powersOfTwo[i] * v[i]) % modulo;
		ans %= modulo;
		ans -= ((int64_t)powersOfTwo[n - i - 1] * v[i]) % modulo;
		ans %= modulo;
	}
	if (ans < 0) {
		ans += modulo;
	}
	cout << ans << endl;
	return 0;
}