#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char a, b;
	char s[200];
	int n, m, l, r;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> a >> b;
		for (int j = l-1; j < r; j++) {
			if (s[j] == a)
				s[j] = b;
		}
	}
	cout << s << nl;

	return 0;
}