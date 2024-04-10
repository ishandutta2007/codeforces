#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int mod = 998244353;

int add(int a, int b) {
	a += b;
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> svi(n);
	vector <int> :: iterator it;
	REP(i, n) {
		cin >> svi[i];
	}
	sort(svi.begin(), svi.end());
	vector <int> pref(n + 1);
	pref[0] = 0;
	REP(i, n) pref[i + 1] = add(pref[i], svi[i]);
	int a, b, k;
	REP(qq, m) {
		cin >> a >> b;
		it = lower_bound(svi.begin(), svi.end(), b);
		k = svi.end() - it;
		if(k < a) cout << "0\n";
		else cout << add(mult(mult(k - a, pot(k, mod - 2)), add(pref[n], -pref[n - k])), mult(mult(k + 1 - a, pot(k + 1, mod - 2)), pref[n - k])) << "\n";
	}
	return 0;
}