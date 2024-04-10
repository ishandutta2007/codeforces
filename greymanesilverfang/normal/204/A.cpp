#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int first_digit(ll x) { while (x > 9) x /= 10; return x; }

inline ll calc(ll x) { return (x < 10 ? x : x / 10 + (first_digit(x) <= x % 10) + 8); }

int main() {
	ll l, r; scanf("%lld%lld", &l, &r);
	printf("%lld", calc(r) - calc(l - 1));
}