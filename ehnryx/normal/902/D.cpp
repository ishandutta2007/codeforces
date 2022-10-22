#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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

#undef M_PI
const ld M_PI = acos(-1);

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> a = {0, 1};
	vector<int> b = {1};
	vector<int> r;

	for (int i = 1; i < n; i++) {
		int sgn = 1;
		for (int j = 1; j < b.size(); j++) {
			if (abs(a[j-1] + b[j]) > 1) {
				sgn = -1;
			}
		}
		r = b;
		b = a;
		a.insert(a.begin(), 0);
		for (int i = 0; i < r.size(); i++) {
			a[i] += sgn*r[i];
		}
	}

	cout << n << nl;
	for (int it : a) cout << it << " "; cout << nl;
	cout << n-1 << nl;
	for (int it : b) cout << it << " "; cout << nl;

	return 0;
}