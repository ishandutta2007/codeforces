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
		int n, maxi = -1, a;
		cin >> n;
		ll rj = 0;
		REP(i, n) {
			cin >> a;
			rj += a;
		}
		REP(i, n) {
			cin >> a;
			rj += a;
			maxi = max(maxi, a);
		}
		cout << rj - maxi << "\n";
	}
	return 0;
}