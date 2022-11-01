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
		ll n, x, y;
		cin >> n >> x >> y;
		int par = 0, a;
		REP(i, n) {
			cin >> a;
			par ^= a % 2;
		}
		x %= 2;
		x ^= par;
		if(x == y % 2) cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}