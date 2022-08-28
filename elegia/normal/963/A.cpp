#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int N = 100010;
const int P = 1000000009;

int n, a, b, k;
ll ans = 0, part;
char s[N];

void exGcd(int a, int b, int& x, int& y);
int rev(int a);
int mpow(int x, int k);

int main() {
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", s);
	ll ra = rev(a), rb = rev(b), an = mpow(a, n), bn = 1;
	for (int i = 0; i < k; ++i) {
		if (s[i] == '+')
			part = (part + (ll)an * bn) % P;
		else
			part = (part + (ll)(P - 1) * an % P * bn % P) % P;
		an = (ll)an * ra % P;
		bn = (ll)bn * b % P;
	}
	ll cyc = (n + 1) / k;
	ll rat = (ll)mpow(ra, k) * mpow(b, k) % P;
	if (rat != 1)
		ans = part * (ll)(1 + P - (ll)mpow(rat, cyc)) % P * rev((1 + P - (ll)rat) % P) % P;
	else
		ans = part * (ll)cyc % P;
	if (ans < 0)
		ans += P;
	printf("%I64d\n", ans);
	return 0;
}

int mpow(int x, int k) {
	int ret = 1;
	while (k) {
		if (k & 1)
			ret = (ll)ret * x % P;
		x = (ll)x * x % P;
		k >>= 1;
	}
	return ret;
}

int rev(int a) {
	int x, y;
	exGcd(a, P, x, y);
	if (x < 0)
		x += P;
	return x;
}

void exGcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1;
		y = 0;
		return;
	}
	exGcd(b, a % b, y, x);
	y -= a / b * x;
}