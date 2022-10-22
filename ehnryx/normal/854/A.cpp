#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	pii ans;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (i < (n-i) && __gcd(i, n-i) == 1) {
			ans = pii(i, n-i);
		}
	}
	cout << ans.first << " " << ans.second << nl;

	return 0;
}