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
		int n, k;
		cin >> n >> k;
		int d, g, a;
		bool ide = 1;
		REP(i, n) {
			cin >> a;
			int tr_d = a, tr_g = a + k - 1;
			if(i == 0) {
				d = tr_d;
				g = tr_d;
				continue;
			}
			tr_d = max(tr_d, d - k + 1);
			tr_g = min(tr_g, g + k - 1);
			if(tr_d > tr_g) {
				ide = 0;
				tr_d = tr_g = 0;
			}
			d = tr_d;
			g = tr_g;
		}
		if(d > a || g < a) ide = 0;
		if(ide) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}