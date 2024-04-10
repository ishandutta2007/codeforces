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
		int n, a, b;
		ll suma = 0;
		cin >> n;
		// ll!
		vector <pair <int, int> > svi(n);
		vector <int> stupnjevi(n, 0);
		REP(i, n) {
			cin >> a;
			svi[i] = make_pair(a, i);
			suma += a;
		}
		sort(svi.begin(), svi.end());
		reverse(svi.begin(), svi.end());
		REP(i, n - 1) {
			cin >> a >> b;
			a--; b--;
			stupnjevi[a]++;
			stupnjevi[b]++;
		}
		cout << suma << " ";
		int ptr = 0;
		REP(k, n) {
			if(k == 0 || k == 1) continue;
			while(stupnjevi[svi[ptr].second] == 1) {
				ptr++;
			}
			stupnjevi[svi[ptr].second]--;
			suma += svi[ptr].first;
			cout << suma << " ";
		}
		cout << "\n";
	}
	return 0;
}