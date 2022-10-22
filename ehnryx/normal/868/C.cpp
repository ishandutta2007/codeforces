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

	unordered_set<int> seen;
	int temp;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a = 0;
		for (int j = 0; j < k; j++) {
			cin >> temp;
			a = (a<<1) + temp;
		}
		seen.insert(a);
		a = ~a;
		for (int bm = 0; bm < (1<<k); bm++) {
			if ((bm | a) == a && seen.count(bm)) {
				cout << "YES" << nl;
				return 0;
			}
		}
	}

	cout << "NO" << nl;

	return 0;
}