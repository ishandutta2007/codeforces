#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n;
		cin >> n;
		vector <ll> svi(n);
		vector <int> bitovi(100, 0);
		REP(i, n) {
			cin >> svi[i];
			REP(j, 61) {
				if(svi[i] & (((ll) 1LL) << j)) bitovi[j]++;
			}
		}
		vector <int> pot(100);
		pot[0] = 1;
		for(int i = 1; i < 100; i++) pot[i] = mult(pot[i - 1], 2);
		int rj = 0;
		REP(i, n) {
			int sand = 0, sor = 0;
			REP(j, 61) {
				if(svi[i] & (((ll) 1LL) << j)) {
					sand = add(sand, mult(pot[j], bitovi[j]));
					sor = add(sor, mult(pot[j], n));
				}
				else {
					sor = add(sor, mult(pot[j], bitovi[j]));
				}
				//cout << j << " " << sand << " " << sor << " " << bitovi[j] << " " << pot[j] << endl;
			}
			//cout << sand << " " << sor << endl;
			rj = add(rj, mult(sand, sor));
		}
		cout << rj << "\n";
	}
	return 0;
}