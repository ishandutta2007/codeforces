#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int hh;
	double h, m, s;
	int t1, t2;
	cin >> hh >> m >> s >> t1 >> t2;
	m += s/60;
	h = hh%12;
	h += m/60;
	h *= 5;
	t1 %= 12;
	t1 *= 5;
	t2 %= 12;
	t2 *= 5;

	cerr << "h: " << h << nl;
	cerr << "m: " << m << nl;
	cerr << "s: " << s << nl;
	cerr << "t1: " << t1 << nl;
	cerr << "t2: " << t2 << nl;

	vector<double> a = { h, m, s, t1, t2 };
	sort(a.begin(), a.end());
	for (int i = 0; i < 5; i++) {
		a.push_back(a[i]);
	}

	for (int i = 1; i < 10; i++) {
		if (a[i] == t1 && a[i-1] == t2 || a[i] == t2 && a[i-1] == t1) {
			cout << "YES" << nl;
			return 0;
		}
	}
	cout << "NO" << nl;

	return 0;
}