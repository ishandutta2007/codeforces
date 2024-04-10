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

	set<int> num;
	int n; int x; int a;
	cin >> n; cin >> x;
	for (int i = 0; i < n; i++) {
		cin >> a;
		num.insert(a);
	}
	int ans = 0;
	for (int i = 0; i < x; i++) {
		if (num.count(i) == 0)
			ans++;
	} if (num.count(x)) {
		ans++;
	} cout << ans << nl;

	return 0;
}