#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a == c) {
			cout << abs(b - d) << "\n";
		}
		else if(b == d) {
			cout << abs(a - c) << "\n";
		}
		else {
			cout << abs(a - c) + 2 + abs(b - d) << "\n";
		}
	}
	return 0;
}