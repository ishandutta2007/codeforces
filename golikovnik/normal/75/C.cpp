#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define endl '\n'
#define make_unique(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

typedef long long ll;
typedef long double ld;
typedef double D;

template<class T = int> inline T read() {
	T x;
	cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(15); cout << fixed;
	set<int> divisors;
	int a = read(), b = read();
	if (a > b) swap(a, b);
	for (int i = 1; i * i <= a; ++i) {
		if (a % i == 0) {
			if (b % i == 0) divisors.insert(i);
			if (b % (a / i) == 0) divisors.insert(a / i);
		}
	}	
	int q = read();
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		auto it = divisors.lower_bound(b);
		if (it != divisors.end() && *it == b) {
			cout << b << endl;
			continue;
		}
		if (it == divisors.begin()) {
			cout << -1 << endl;
			continue;
		}
		--it;
		if (*it < a) {
			cout << -1 << endl;
		} else cout << *it << endl;
	}
	return 0;
}