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

	ll ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if ((ax-bx)*(ax-bx) + (ay-by)*(ay-by) == (bx-cx)*(bx-cx) + (by-cy)*(by-cy)
			&& (ay-by)*(bx-cx) != (ax-bx)*(by-cy))
		cout << "YES" << nl;
	else cout << "NO" << nl;

	return 0;
}