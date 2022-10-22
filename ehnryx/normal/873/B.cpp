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

	int n;
	string s;
	cin >> n;
	cin >> s;

	int sum[n+1];
	int last[2*n+1];

	sum[0] = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			sum[i+1] = sum[i]-1;
		else
			sum[i+1] = sum[i]+1;
		last[n + sum[i]] = i;
	}
	last[n + sum[n]] = n;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, last[n + sum[i]] - i);
	}
	cout << ans << nl;

	return 0;
}