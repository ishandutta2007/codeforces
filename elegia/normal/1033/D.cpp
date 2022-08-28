#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 510, P = 998244353;

ll pw(ll x, int k) {
	ll ret = 1;
	while (k) {
		if (k & 1)
			ret *= x;
		x *= x;
		k >>= 1;
	}
	return ret;
}

int decomp(ll x, int k) {
	int guess = pow(x, 1. / k);
	while (pw(guess, k) < x)
		++guess;
	if (pw(guess, k) == x)
		return guess;
	return -1;
}

int mpow(int x, int k) {
	int ret = 1;
	while (k) {
		if (k & 1)
			ret = ret * (ll)x % P;
		x = x * (ll)x % P;
		k >>= 1;
	}
	return ret;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

map<ll, int> pr;

int cnt = 0;
int c[N], a[N];
ll v[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n;
	scanf("%d", &n);
	while (n--) {
		ll x;
		scanf("%lld", &x);
		int guess = -1;
		for (int i = 4; i >= 2; --i) {
			guess = decomp(x, i);
			if (guess != -1) {
				pr[guess] += i;
				break;
			}
		}
		if (guess == -1)
			v[++cnt] = x;
	}
	fill(a + 1, a + cnt + 1, 1);
	for (int i = 1; i <= cnt; ++i) {
		if (v[i] < 0)
			continue;
		for (int j = i + 1; j <= cnt; ++j) {
			if (v[j] < 0)
				continue;
			if (v[i] != v[j]) {
				ll g = gcd(v[i], v[j]);
				if (g != 1)
					pr[g] += 0;
			} else {
				v[j] = -1;
				++a[i];
				a[j] = 0;
			}
		}
	}
	fill(c + 1, c + cnt + 1, 2);
	int ans = 1;
	for (map<ll, int>::iterator it = pr.begin(); it != pr.end(); ++it) {
		for (int i = 1; i <= cnt; ++i)
			if (v[i] > 0 && v[i] % it->first == 0) {
				v[i] /= it->first;
				it->second += a[i];
				--c[i];
			}
		ans = ans * (it->second + 1LL) % P;
	}
	for (int i = 1; i <= cnt; ++i) {
		ans = ans * (ll) mpow(a[i] + 1, c[i]) % P;
	}
	printf("%d\n", ans);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}