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
		int n;
		ll s = 0, s1 = 0, s2 = 0;
		cin >> n;
		vector <int> svi(n);
		REP(i, n) {
			cin >> svi[i];
			s += svi[i];
		}
		REP(i, n) {
			if(i % 2 == 0) s1 += svi[i] - 1;
			else s2 += svi[i] - 1;
		}
		if(2 * s1 <= s) {
			REP(i, n) {
				if(i % 2 == 0) cout << 1 << " ";
				else cout << svi[i] << " ";
			}
		}
		else {
			REP(i, n) {
				if(i % 2) cout << 1 << " ";
				else cout << svi[i] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}