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
		vector <int> niz(n);
		vector <vector <int> > pf(n, vector <int>());
		int maxi = 0;
		REP(i, n) {
			cin >> niz[i];
			if(niz[i] > maxi) {
				maxi = niz[i];
			}
			int pom = niz[i];
			//pf[i].push_back(1);
			for(int j = 2; j <= pom; j++) {
				while(pom % j == 0) {
					pom /= j;
					pf[i].push_back(j);
				}
			}
		}
		vector <int> rj(n);
		rj[0] = maxi;
		REP(i, n) {
			if(niz[i] == maxi) {
				niz[i] = 0;
				break;
			}
		}
		int gcd = maxi, tr_gcd, pom_gcd, max_gcd, ind;
		REP(i, n - 1) {
			max_gcd = 0;
			REP(j, n) {
				if(niz[j] == 0) continue;
				pom_gcd = gcd;
				tr_gcd = 1;
				REP(k, (int)pf[j].size()) {
					//cout << pom_gcd << " " << pf[j][k] << endl;
					if(pom_gcd % pf[j][k] == 0) {
						tr_gcd *= pf[j][k];
						pom_gcd /= pf[j][k];
					}
				}
				//cout << niz[j] << " " << tr_gcd << " " << gcd << endl;
				if(tr_gcd > max_gcd) {
					max_gcd = tr_gcd;
					ind = j;
				}
			}
			rj[i + 1] = niz[ind];
			niz[ind] = 0;
			gcd = max_gcd;
		}
		REP(i, n) cout << rj[i] << " ";
		cout << "\n";
	}
	return 0;
}