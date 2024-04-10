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

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	n++;

	int a[n];
	int last = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[i] > 1 && a[i-1] > 1) {
			last = i;
		}
	}

	if (!last) {
		cout << "perfect" << nl;
	} else {
		vector<int> x, y;
		int prev = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a[i]; j++) {
				x.push_back(prev);
				y.push_back(prev);
			}
			if (i == last) {
				y.back() = prev-1;
			}
			prev = x.size();
		}
		cout << "ambiguous" << nl;
		for (int it : x) cout << it << " "; cout << nl;
		for (int it : y) cout << it << " "; cout << nl;
	}

	return 0;
}