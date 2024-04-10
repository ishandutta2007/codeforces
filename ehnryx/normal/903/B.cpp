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

	int h1, a1, c, h2, a2;
	cin >> h1 >> a1 >> c >> h2 >> a2;

	vector<string> ans;
	while (h2 > 0) {
		if (h2 <= a1) {
			ans.push_back("STRIKE");
			break;
		} else {
			if (h1 <= a2) {
				ans.push_back("HEAL");
				h1 += c;
			} else {
				ans.push_back("STRIKE");
				h2 -= a1;
			}
		}
		h1 -= a2;
	}

	cout << ans.size() << nl;
	for (const string& s : ans) {
		cout << s << nl;
	}

	return 0;
}