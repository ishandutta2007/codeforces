#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> svi(n);
	REP(i, n) cin >> svi[i];
	vector <vector <int> > skupine(1, vector <int>(n));
	REP(i, n) skupine[0][i] = svi[i];
	ll rj = 0, x = 0;
	for(int i = 30; i >= 0; i--) {
		ll mini = 0;
		REP(j, (int)skupine.size()) {
			ll jed = 0;
			REP(k, (int)skupine[j].size()) {
				if((1 << i) & (skupine[j][k])) jed++;
				else mini += jed;
			}
		}
		ll pot = 0;
		REP(j, (int)skupine.size()) {
			ll jed = 0;
			REP(k, (int)skupine[j].size()) {
				if((1 << i) & (skupine[j][k])) pot += jed;
				else jed++;
			}
		}
		//cout << i << endl;
		//cout << mini << " " << pot << endl;
		if(pot < mini) {
			rj += pot;
			x |= (1 << i);
			REP(j, (int)skupine.size()) {
				REP(k, (int)skupine[j].size()) {
					skupine[j][k] ^= (1 << i);
				}
			}
		}
		else rj += mini;
		vector <vector <int> > novi;
		REP(j, (int)skupine.size()) {
			vector <int> ubaci1, ubaci2;
			REP(k, (int)skupine[j].size()) {
				if(skupine[j][k] & (1 << i)) ubaci1.push_back(skupine[j][k]);
				else ubaci2.push_back(skupine[j][k]);
			}
			if(ubaci1.size()) novi.push_back(ubaci1);
			if(ubaci2.size()) novi.push_back(ubaci2);
		}
		skupine = novi;
	}
	cout << rj << " " << x << "\n";
	return 0;
}