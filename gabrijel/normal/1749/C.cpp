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
		int n, a, maxi = 0;
		cin >> n;
		multiset <int> orig, svi;
		REP(i, n) {
			cin >> a;
			orig.insert(-a);
		}
		for(int k = 1; k <= (n + 1) / 2; k++) {
			svi = orig;
			bool ok = 1;
			REP(i, k) {
				while((int)svi.size() && -*(svi.begin()) > k - i) svi.erase(svi.begin());
				if(!svi.size()) {
					ok = 0;
					break;
				}
				svi.erase(svi.begin());
				if(svi.size()) {
					multiset <int>::iterator it = svi.end();
					it--;
					svi.erase(it);
				}
			}
			if(ok) maxi = k;
		}
		cout << maxi << "\n";
	}
	return 0;
}