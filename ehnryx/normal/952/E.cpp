#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef mt19937 RNG;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;

int next_square(int n) {
	int res = sqrt(n);
	while (res*res < n) res++;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	int hard, soft;
	hard = soft = 0;

	string s, t;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		if (t == "hard") hard++;
		else soft++;
	}

	if (hard == soft) cout << next_square(2*hard) << nl;
	else cout << next_square(2*max(hard,soft)-1) << nl;

	return 0;
}