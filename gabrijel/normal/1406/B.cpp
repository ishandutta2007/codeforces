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
		vector <pair <int, bool> > svi(n);
		int a;
		bool svi_neg = 1;
		REP(i, n) {
			cin >> a;
			if(a < 0) svi[i] = make_pair(-a, 1);
			else {svi[i] = make_pair(a, 0); svi_neg = 0;}
		}
		sort(svi.begin(), svi.end());
		reverse(svi.begin(), svi.end());
		ll sol = 1LL;
		int neg = 0;
		bool imam_par = 0, imam_nep = 0;
		int zad_par = -1, zad_nep = -1;
		REP(i, 5) {
			if(svi[i].second) {zad_nep = svi[i].first; imam_nep = 1;}
			else {zad_par = svi[i].first; imam_par = 1;}
			sol *= svi[i].first;
			neg += svi[i].second;
		}
		if(neg % 2 == 0 || zad_par == 0) {
			cout << sol << "\n";
			continue;
		}
		if(svi_neg) {
			sol = 1LL;
			REP(i, 5) {
				sol *= svi[n - 1 - i].first;
			}
			cout << -sol << "\n";
			continue;
		}
		ll pom_sol = -1LL;
		for(int i = 5; i < n; i++) {
			if(svi[i].second) {
				if(imam_par) {
					pom_sol = max(pom_sol, (sol / zad_par) * svi[i].first);
				}
			}
			else {
				if(imam_nep) {
					pom_sol = max(pom_sol, (sol / zad_nep) * svi[i].first);
				}
			}
		}
		if(pom_sol == -1LL) cout << -sol << "\n";
		else cout << pom_sol << "\n";
	}
	return 0;
}