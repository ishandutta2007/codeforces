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

	int n, x;
	cin >> n >> x;
	if (n == 2 && x == 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << nl;
	if (n == 1) {
		cout << x << nl;
	} else if (n == 2) {
		if (x) cout << 0 << " " << x << nl;
	}
	else {
		vector<int> ans;
		for (int i = 3; i < n; i++) {
			ans.push_back(i);
			x ^= i;
		}
		ans.push_back(500000);
		ans.push_back(200002);
		ans.push_back(500000^200002^x);
		for (int it: ans) {
			cout << it << " ";
		} cout << nl;
	}

	return 0;
}