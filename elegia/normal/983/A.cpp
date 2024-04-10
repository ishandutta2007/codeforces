#include <cstdio>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b);

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		ll p, q, b, g;
		scanf("%lld%lld%lld", &p, &q, &b);
		g = gcd(p, q);
		p /= g;
		q /= g;
		g = gcd(q, b);
		while (q != 1) {
			g = gcd(q, g);
			if (g == 1)
				break;
			q /= g;
		}
		if (q == 1)
			puts("Finite");
		else
			puts("Infinite");
	}
	return 0;
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}