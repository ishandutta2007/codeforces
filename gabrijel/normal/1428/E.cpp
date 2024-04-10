#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, k, a, b;
	cin >> n >> k;
	k = k - n;
	multiset <pair <pair <ll, ll>, pair <ll, ll> > > ustede;
	ll rj = 0;
	REP(i, n) {
		cin >> a;
		rj += a * a;
		if(a == 1) continue;
		ll dij = a / 2, ost = a % 2;
		ll usteda = a * a - dij * dij * (2 - ost) - (dij + 1) * (dij + 1) * (ost);
		ustede.insert(make_pair(make_pair(-usteda, a * a - usteda), make_pair(a, 1)));
	}
	while(k && ustede.size()) {
		pair <pair <ll, ll>, pair <ll, ll> > tr_par = *ustede.begin();
		ll tr_usteda = tr_par.first.first, trenutni = tr_par.first.second;
		a = tr_par.second.first;
		b = tr_par.second.second;
		rj += tr_usteda;
		k--;
		//cout << k << endl;
		ustede.erase(ustede.begin());
		//cout << tr_usteda << " " << trenutni << " " << a << " " << b << endl;
		if(b >= a - 1) continue;
		ll dij = a / (b + 2), ost = a % (b + 2);
		ll usteda = trenutni - (dij * dij * (b + 2 - ost) + (dij + 1) * (dij + 1) * (ost));
		//cout << usteda << endl;
		ustede.insert(make_pair(make_pair(-usteda, trenutni - usteda), make_pair(a, b + 1)));
	}
	cout << rj << "\n";
	return 0;
}