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
		vector <ll> svi(n);
		ll suma = 0;
		REP(i, n) {
			cin >> svi[i];
			suma += svi[i];
		}
		if(suma % n != 0) {
			cout << "-1\n";
			continue;
		}
		suma /= n;
		vector <pair <pair <ll, ll>, ll> > rj;
		for(int i = 1; i < n; i++) {
			ll ind = i + 1;
			ll ost = svi[i] % ind;
			ost = ind - ost;
			if(ost != ind) {
				rj.push_back(make_pair(make_pair(1, ind), ost));
				svi[i] += ost;
				svi[0] -= ost;
			}
			rj.push_back(make_pair(make_pair(ind, 1), svi[i] / ind));
			svi[0] += svi[i];
			svi[i] = 0;
		}
		for(int i = 1; i < n; i++) {
			rj.push_back(make_pair(make_pair(1, i + 1), suma));
		}
		cout << (int)rj.size() << "\n";
		REP(i, (int)rj.size()) {
			cout << rj[i].first.first << " " << rj[i].first.second << " " << rj[i].second << "\n";
		}
	}
	return 0;
}