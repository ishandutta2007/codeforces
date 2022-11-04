#include <bits/stdc++.h>
typedef int ll;
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 	cout.tie(0);
	ll t, n;
	string s;
	cin >> t;
	for (ll iii = 0; iii < t; ++iii) {
		cin >> n;
		cin >> s;
		unordered_map<double, ll> m;
		m.reserve(n*2);
		double K = 0, D = 0;
		for (auto& i : s) {
			K += i == 'K';
			D += i == 'D';
			auto a = m.find(K/D);
			if (a == m.end()) {
				cout << "1 ";
				m[K/D] = 1;
			} else {
				cout << ++(a->second) << ' ';
			}
		}
		cout << '\n';
	}
}