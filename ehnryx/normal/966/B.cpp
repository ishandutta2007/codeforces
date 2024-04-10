#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, x1, x2;
	cin >> n >> x1 >> x2;

	vector<pii> vals;
	int c;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		vals.push_back(pii(c,i));
	}
	sort(vals.begin(), vals.end());

	// try a then b
	{
		int sz;
		for (sz = 1; sz <= n; sz++) {
			if (x1 <= vals[n-sz].first*sz) break;
		}
		int first = n-sz;
		for (sz = 1; sz <= first; sz++) {
			if (x2 <= vals[first-sz].first*sz) break;
		}
		int second = first-sz;
		if (second >= 0 && x2 <= vals[second].first*sz) {
			cout << "Yes" << nl;
			cout << n-first << " " << first-second << nl;
			for (int i = first; i < n; i++) cout << vals[i].second << " ";
			cout << nl;
			for (int i = second; i < first; i++) cout << vals[i].second << " ";
			cout << nl;
			return 0;
		}
	}

	// try b then a
	{
		int sz;
		for (sz = 1; sz <= n; sz++) {
			if (x2 <= vals[n-sz].first*sz) break;
		}
		int first = n-sz;
		for (sz = 1; sz <= first; sz++) {
			if (x1 <= vals[first-sz].first*sz) break;
		}
		int second = first-sz;
		if (second >= 0 && x1 <= vals[second].first*sz) {
			cout << "Yes" << nl;
			cout << first-second << " " << n-first << nl;
			for (int i = second; i < first; i++) cout << vals[i].second << " ";
			cout << nl;
			for (int i = first; i < n; i++) cout << vals[i].second << " ";
			cout << nl;
			return 0;
		}
	}

	// bad
	cout << "No" << nl;

	return 0;
}