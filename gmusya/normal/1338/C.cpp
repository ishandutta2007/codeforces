#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

typedef long long ll;

struct ans {
	ll a, b, c;
};

ans rec(ll n) {
	if (n == 1) return { 1, 2, 3 };
	n += 2;
	auto tmp = rec(n / 4);
	ll a = tmp.a, b = tmp.b, c = tmp.c;
	a *= 4, b *= 4, c *= 4;
	if (n % 4 == 1) a += 1, b += 2, c += 3;
	if (n % 4 == 2) a += 2, b += 3, c += 1;
	if (n % 4 == 3) a += 3, b += 1, c += 2;
	return { a, b, c };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		auto tmp = rec((n + 2) / 3);
		if (n % 3 == 1) cout << tmp.a << endl;
		if (n % 3 == 2) cout << tmp.b << endl;
		if (n % 3 == 0) cout << tmp.c << endl;
	}
	return 0;
}