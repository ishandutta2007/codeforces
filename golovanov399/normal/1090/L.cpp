#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	long long t, n, a, b, k;
	cin >> t >> n >> a >> b >> k;
	long long ca = (n + 1) / 2;
	long long cb = (n + 0) / 2;
	if (a < b) {
		swap(a, b);
		swap(ca, cb);
	}

	if (k > n) {
		cout << "0\n";
		return 0;
	}
	if (k == n) {
		cout << min({t, a, b}) << "\n";
		return 0;
	}
	if (k > ca && (b * cb) / (k - ca) < a) {
		cout << min(t, (b * cb) / (k - ca)) << "\n";
		return 0;
	}
	cout << min(t, (1ll * ca * a + 1ll * cb * b) / k) << "\n";

	return 0;
}