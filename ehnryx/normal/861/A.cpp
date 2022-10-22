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

	int twos, fives;
	ll n;
	int k;
	cin >> n >> k;
	twos = fives = 0;
	for (ll temp = n; temp%2 == 0; temp/=2)
		twos++;
	for (ll temp = n; temp%5 == 0; temp/=5)
		fives++;
	for (int count = min(twos, fives); count < k; count++) {
		if (twos < fives) {
			n *= 2;
			twos++;
		} else if (twos > fives) {
			n *= 5;
			fives++;
		} else {
			n *= 10;
		}
	}
	cout << n << nl;

	return 0;
}