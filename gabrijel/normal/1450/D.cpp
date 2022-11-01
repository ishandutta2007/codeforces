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
		cin >> n;
		vector <int> svi(n);
		vector <vector <int> > poz(n, vector <int>());
		REP(i, n) {
			cin >> svi[i];
			poz[svi[i] - 1].push_back(i);
		}
		vector <int> maxi(n + 1, 0);
		set <int> akt_poz;
		set <int>::iterator it;
		int l, r;
		akt_poz.insert(-1);
		akt_poz.insert(n);
		REP(i, n) {
			for(int tr_poz : poz[i]) {
				it = akt_poz.lower_bound(tr_poz);r = *it;
				it--;
				l = *it;
				maxi[r - l - 1] = max(maxi[r - l - 1], i + 1);
			}
			for(int tr_poz : poz[i]) {
				akt_poz.insert(tr_poz);
			}
		}
		for(int i = n; i >= 0; i--) if(i < n) maxi[i] = max(maxi[i], maxi[i + 1]);
		//for(int i = n; i >= 0; i--) cout << maxi[i] << endl;
		int d_g = 0, pl = 0, pr = n - 1;
		REP(i, n) {
			bool imam_l = 0, imam_r = 0, kraj = 0;
			for(int tr_poz : poz[i]) {
				if(tr_poz == pl) imam_l = 1;
				else if(tr_poz == pr) imam_r = 1;
				else kraj = 1;
			}
			if(kraj || (imam_l && imam_r)) {
				d_g = pr - pl + 1;
				break;
			}
			else if(imam_l) pl++;
			else if(imam_r) pr--;
		}
		//cout << d_g << endl;
		bool imam[n] = {0};
		REP(i, n) imam[svi[i] - 1] = 1;
		bool ok = 1;
		REP(i, n) {
			if(!imam[i]) {
				ok = 0;
				break;
			}
		}
		cout << ok;
		for(int i = 1; i < n; i++) {
			if(maxi[i + 1] == n - i && i + 1 >= d_g) cout << "1";
			else cout << "0";
		}
		cout << "\n";
	}
	return 0;
}