#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double PI = 3.14159265358979;
const double E = 2.718281828459045;
const double root2 = sqrt(2);
typedef pair<int, int> P;
typedef unsigned int ui;
ll gcd(ll x, ll y) {
	if (x < y)swap(x, y);
	ll r = x % y;
	while (r != 0) {
		x = y; y = r; r = x % y;
	}
	return y;
}
int main() {
	int n; ll a, b, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a);
		scanf("%lld", &b);
		scanf("%lld", &d);
		if (a == 0) {
			cout << "Finite" << endl;
			continue;
		}
		b /= gcd(a, b);
		ll x = gcd(b, d);
		while (x != 1) {
			while (b%x == 0)b /= x;
			x = gcd(b, x);
		}
		if (b == 1)printf("%s\n", "Finite");
		else printf("%s\n", "Infinite");
	}
	return 0;
}