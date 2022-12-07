#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define cat(x) cout << #x << ": " << x << endl

using ll = long long;
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	set<int> s = {1, 2};
	int a = __gcd(n - 1, m - 1);
	int b = __gcd(n, m - 2);
	int c = __gcd(n - 2, m);
	//cat(a);cat(b);cat(c);
	
	for (auto x : {a, b, c}) {
		auto consider = [&](int g) {
			if (g == 0) return;
			if (a % g == 0 || b % g == 0 || c % g == 0)
				s.insert(g);
		};
		for (int i = 1; i * i <= min(n, m); i++) {
			consider(i);
			consider(a / i);
			consider(b / i);
			consider(c / i);
		}
	}

	cout << s.size() << " ";
	for (auto x : s) cout << x << " ";
	cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}