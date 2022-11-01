#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 998244353;
const int maxn = 300100;

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

int mult(int a, int b) {
	return (ll)a * b % mod;
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

int dij(int a, int b) {
	return mult(a, pot(b, mod - 2));
}

vector <int> prosti;
int djelitelj[maxn];

void euler() {
	for(int i = 2; i < maxn; i++) {
		if(!djelitelj[i]) {
			prosti.push_back(i);
			djelitelj[i] = i;
		}
		for(int j = 0; prosti[j] * i < maxn; j++) {
			djelitelj[prosti[j] * i] = prosti[j];
			if(i % prosti[j] == 0) break;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	euler();
	int n;
	cin >> n;
	ll m, ostalo = 1;
	cin >> m;
	int rj = 0, zad = 0, tr_pot = 1;
	for(int i = 2; i <= n; i++) {
		tr_pot = mult(tr_pot, m % mod);
		if(ostalo <= m && djelitelj[i] == i) ostalo *= i;
		int trrj = 0, losi = (m / ostalo) % mod;
		trrj = add(trrj, mult(tr_pot, (m - losi) % mod));
		trrj = add(trrj, mult(losi, zad));
		rj = add(rj, trrj);
		zad = trrj;
		//cout << trrj << endl;
	}
	cout << rj << "\n";
	return 0;
}