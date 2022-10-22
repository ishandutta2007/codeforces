#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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

	int n, a, b;
	cin >> n >> a >> b;
	int total = a+b;

	string s;
	cin >> s;

	int prev = -1;
	for (char c : s) {
		if (c == '*') {
			prev = -1;
		}
		else {
			if (prev == -1) {
				if (a > b) {
					a--;
					prev = 1;
				} else {
					b--;
					prev = 2;
				}
			}
			else if (prev == 1) {
				b--;
				prev = 2;
			}
			else {
				a--;
				prev = 1;
			}
		}
	}

	cout << total - max(0, a) - max(0, b) << nl;

	return 0;
}