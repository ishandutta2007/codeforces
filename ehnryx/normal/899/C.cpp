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
	switch (n%4) {
		case 0:
			cout << 0 << nl;
			cout << n/2 << " ";
			for (int i = 1; i <= n/4; i++) {
				cout << i << " " << n-i+1 << " ";
			}
			cout << nl;
			break;
		case 1:
			cout << 1 << nl;
			cout << n/2 << " ";
			for (int i = 1; i <= n/4; i++) {
				cout << i+1 << " " << n-i+1 << " ";
			}
			cout << nl;
			break;
		case 2:
			cout << 1 << nl;
			cout << n/2 << " ";
			for (int i = 1; i <= n/4; i++) {
				cout << i+2 << " " << n-i+1 << " ";
			}
			cout << 1 << nl;
			break;
		case 3:
			cout << 0 << nl;
			cout << n/2 << " ";
			for (int i = 1; i <= n/4; i++) {
				cout << i+3 << " " << n-i+1 << " ";
			}
			cout << 3 << nl;
			break;
	}

	return 0;
}