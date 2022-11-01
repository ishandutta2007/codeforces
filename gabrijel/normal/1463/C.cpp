#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	REP(ttt, tt) {
		ll n, t, x, poz = 0, slobodan = 0, rj = 0, dest = 0;
		cin >> n;
		vector <pair <ll, ll> > svi;
		REP(i, n) {
			cin >> t >> x;
			svi.push_back(make_pair(t, x));
		}
		svi.push_back(make_pair(4e9 + 100, 0));
		REP(i, n) {
			if(slobodan <= svi[i].first) {
				poz = dest;
				if((ll) svi[i + 1].first >= (ll) svi[i].first + llabs(poz - svi[i].second)) rj++;
				dest = svi[i].second;
				slobodan = (ll) svi[i].first + llabs(poz - svi[i].second);
			}
			else {
				if(poz == dest) {
					if(svi[i].second == poz) rj++;
				}
				else if(poz < dest) {
					if(svi[i].second >= poz && svi[i].second <= dest) {
						ll pom = svi[i + 1].first - svi[i].first;
						if((ll) svi[i].second <= (ll) poz + pom) rj++;
					}
				}
				else { // poz > dest
					if(svi[i].second <= poz && svi[i].second >= dest) {
						ll pom = svi[i + 1].first - svi[i].first;
						if((ll) svi[i].second >= (ll) poz - pom) rj++;
					}
				}
			}
			ll pom = svi[i + 1].first - svi[i].first;
			if(poz == dest) continue;
			else if(poz < dest) {
				poz = min((ll) dest, (ll) poz + pom);
			}
			else {
				poz = max((ll) dest, (ll) poz - pom);
			}
		}
		cout << rj << "\n";
	}
	return 0;
}