#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		ll ma = (1LL << m) - 1, sz = (1LL << m) - n;
		vector <ll> a(n);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++)
				a[i] = (a[i] * 2) + (s[j] - '0');
		}
		sort(a.begin(), a.end());
		ll L = 0, R = ma, MED = (sz + 1) / 2;
		while (L != R) {
			ll M = (L + R) / 2;
			auto lb = lower_bound(a.begin(), a.end(), M);
			auto ub = upper_bound(a.begin(), a.end(), M);
			ll pos = 1 + M - (ub - a.begin());
			if (ub != lb) {
				if (pos < MED) L = M + 1;
				else R = M - 1;
				continue;
			}
			if (pos < MED) L = M + 1;
			else R = M;
		}
		string s;
		while (L) {
			s += (L % 2) + '0';
			L /= 2;
		}
		while (s.size() < m) s += '0';
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
}