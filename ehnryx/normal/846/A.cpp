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

	int n;
	cin >> n;
	int game[n];
	int good[n+1];
	int bad[n+1];
	bad[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> game[i];
		bad[i+1] = bad[i] + !game[i];
	}
	good[n] = 0;
	for (int i = n-1; i >= 0; i--) {
		good[i] = good[i+1] + game[i];
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, good[i] + bad[i]);
	}
	cout << ans << nl;

	return 0;
}