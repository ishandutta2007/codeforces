#include <bits/stdc++.h>
using namespace std;

#define INF (1LL<<32)
typedef long long LL;
const double PI = 4 * atan(1);

int L;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> L;
	LL ans = 0;
	LL mult = 1;
	stack<int> s;
	int debt = 0;
	while (L--) {
		string typ;
		cin >> typ;
		if (typ[0] == 'a') {
			ans += mult;
			if (ans >= INF) {
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
		}
		else if (typ[0] == 'e') {
			if (debt)
				--debt;
			else {
				mult /= s.top();
				s.pop();
			}
		}
		else {
			int n; cin >> n;
			if (mult >= INF)
				++debt;
			else
				mult *= n, s.push(n);
		}
	}

	cout << ans << endl;
	return 0;
}