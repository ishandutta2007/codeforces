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
	vector<int> b = {
		31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int lim = 8*12;
	for (int j = 0; j+n < lim; j++) {
		bool shit = false;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[j+i]) {
				shit = true;
				break;
			}
		}
		if (!shit) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}