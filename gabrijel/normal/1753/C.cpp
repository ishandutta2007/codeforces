#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 998244353;

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
	while(b)
	{
		if(b & 1) ret = mult(ret, a);
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

int dij(int a, int b) {
	return mult(a, pot(b, mod - 2));
}

vector <int> svi;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	REP(tt, t) {
		int n, cnt = 0, k = 0, rj = 0;
		cin >> n;
		svi.clear();
		svi.resize(n);
		REP(i, n) {
			cin >> svi[i];
			cnt += svi[i];
		}
		REP(i, n) {
			if(i < n - cnt) k += svi[i];
			else k += !svi[i];
		}
		k /= 2;
		int pov = dij(mult(n, n - 1), 2);
		for(int i = 1; i <= k; i++) rj = add(rj, dij(pov, mult(i, i)));
		cout << rj << "\n";
	}
	return 0;
}