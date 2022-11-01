#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

ll pot[60];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	pot[0] = 1;
	REP(i, 59) pot[i + 1] = pot[i] * 2;
	REP(tt, t) {
		ll n;
		cin >> n;
		int sol = 0;
		REP(i, 32) {
			ll tr = pot[i + 1] - 1;
			if(tr * (tr + 1) / 2 <= n) {
				sol++;
				n -= tr * (tr + 1) / 2;
			}
			else break;
		}
		cout << sol << "\n";
	}
	return 0;
}