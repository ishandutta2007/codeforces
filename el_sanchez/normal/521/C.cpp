#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ld pi = acos(-1.0);
const ld eps = 1e-14;
const int INF = 1E9;		
const int MAXN = 100500;
const ll MOD = 1E9 + 7;

ll inv(ll x) {
	ll res = 1, p = MOD - 2;
	while (p > 0) {
		if (p & 1)
			res = (res * x) % MOD;	
		x = (x * x) % MOD;
		p >>= 1;
	}
	return res;
}

int n, k, a[MAXN];
string s;
ll Cnk[MAXN], Cnkk[MAXN], p10, sum, res;

int main() {

	cin >> n >> k;
	cin >> s;
	forn(i, n) {
		a[i] = s[i] - '0';
	}
	
	for (int i = 0; i < k - 1; i++)
		Cnk[i] = 0;
	Cnk[k - 1] = 1;
	for (int i = k; i <= n - 1; i++) {
		Cnk[i] = (Cnk[i - 1] * i) % MOD;
		Cnk[i] = (Cnk[i] * inv(i - k + 1)) % MOD;	
	}
	
	for (int i = 0; i < k; i++)
		Cnkk[i] = 0;
	Cnkk[k] = 1;
	for (int i = k + 1; i <= n - 1; i++) {
		Cnkk[i] = (Cnkk[i - 1] * i) % MOD;
		Cnkk[i] = (Cnkk[i] * inv(i - k)) % MOD;	
	}

	p10 = 1;
	for (int i = n - 2; i >= 0; i--) {
		Cnk[i] = (Cnk[i] * p10) % MOD;
		p10 = (p10 * 10) % MOD;	
	}
	
	sum = 0;
	for (int i = n - 2; i >= 0; i--)
		sum = (sum + Cnk[i]) % MOD;
		
	res = 0;
	for (int i = 0; i <= n - 2; i++) {
		res = (res + sum * a[i]) % MOD;
		sum = (sum + MOD * MOD - Cnk[i]) % MOD;	
		//cout << res << '\n';
	}

	p10 = 1;
	for (int i = n - 1; i >= 0; i--) {
		res = (res + Cnkk[i] * p10 % MOD * a[i]) % MOD;
		p10 = (p10 * 10) % MOD;
	}
	
	cout << res << '\n';
	
	return 0;
}