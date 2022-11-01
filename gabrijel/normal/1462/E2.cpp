#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 1e9 + 7;
const int maxn = 200100;

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % mod;
}

int pot(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = mult(ret, a);
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

vector <int> fakt, inv_fakt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fakt.resize(maxn);
	inv_fakt.resize(maxn);
	fakt[0] = 1;
	inv_fakt[0] = 1;
	for(int i = 1; i < maxn; i++) {
		fakt[i] = mult(fakt[i - 1], i);
		inv_fakt[i] = pot(fakt[i], mod - 2);
	}
	int t;
	cin >> t;
	REP(tt, t) {
		int n, m, k, a;
		cin >> n >> m >> k;
		if(k == n) k--;
		vector <int> kolko(n, 0);
		REP(i, n) {
			cin >> a;
			kolko[a - 1]++;
		}
		int ukupno = 0, trenutni, rj = 0;
		REP(i, k + 1) ukupno += kolko[i];
		REP(i, n) {
			trenutni = kolko[i];
			if(ukupno >= m) rj = add(rj, mult(fakt[ukupno], mult(inv_fakt[m], inv_fakt[ukupno - m])));
			if(ukupno - trenutni >= m) rj = add(rj, -mult(fakt[ukupno - trenutni], mult(inv_fakt[m], inv_fakt[ukupno - trenutni - m])));
			//cout << i << " " << ukupno << " " << trenutni << " " << rj << endl;
			ukupno -= kolko[i];
			if(i + k + 1 <= n - 1) ukupno += kolko[i + k + 1];
		}
		cout << rj << "\n";
	}
	return 0;
}