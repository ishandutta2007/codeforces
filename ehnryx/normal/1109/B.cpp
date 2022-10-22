#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e12-11;
const ll P = 2017;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	string s;
	cin >> s;
	int n = s.size();

	set<char> seen;
	for (int i=0; i<n/2; i++) {
		seen.insert(s[i]);
	}
	if (seen.size() <= 1) {
		cout << "Impossible" << nl;
		return 0;
	}

	ll ha = 0;
	ll mul = 1;
	for (int i=0; i<n; i++) {
		ha = (ha*P + s[i]) % MOD;
		mul = mul*P % MOD;
	}

	ll init = ha;
	for (int i=1; i<n; i++) {
		ha = (ha*P + s[i-1]) % MOD;
		ha = ((ha - mul*s[i-1]) % MOD + MOD) % MOD;
		if (ha == init) continue;
		bool ok = true;
		for (int j=0; j<n/2; j++) {
			if (s[(i+j)%n] != s[(i-j-1+3*n)%n]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "1" << nl;
			return 0;
		}
	}

	cout << "2" << nl;

	return 0;
}