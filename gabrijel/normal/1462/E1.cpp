#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 1e9 + 7;
const int maxn = 200100;

vector <ll> povrh;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	povrh.resize(maxn);
	REP(i, maxn) povrh[i] = (ll) i * (i - 1) * (i - 2) / 6;
	int t;
	cin >> t;
	REP(tt, t) {
		ll n, m, k, a;
		cin >> n;
		m = 3;
		k = 2;
		if(k >= n) k = n - 1;
		vector <ll> kolko(n, 0);
		REP(i, n) {
			cin >> a;
			kolko[a - 1]++;
		}
		ll ukupno = 0, trenutni, rj = 0;
		REP(i, k + 1) ukupno += kolko[i];
		REP(i, n) {
			trenutni = kolko[i];
			if(ukupno >= m) rj += povrh[ukupno];
			if(ukupno - trenutni >= m) rj -= povrh[ukupno - trenutni];
			ukupno -= kolko[i];
			if(i + k + 1 <= n - 1) ukupno += kolko[i + k + 1];
		}
		cout << rj << "\n";
	}
	return 0;
}