#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <random>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve() {
	long long n, x;
	cin >> n >> x;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	long long c = (a[1] - a[0]);
	for (int i = 2; i < n; ++i) {
		if (a[i] == x || a[0] == x || a[1] == x) {
			cout << "YES\n";
			return;
		}
		c = gcd(c, a[i] - a[i - 1]);
	}
	if (c == 0) {
		if (x == a[0])
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	c = abs(c);
	if ((x % c + c) % c == (a.back() % c + c) % c)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}