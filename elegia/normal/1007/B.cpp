#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <functional>
#include <set>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 100010;

ll cnt[N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
ll sum2(ll n) { return n * (n + 1) / 2; }
ll sum3(ll n) { return n * (n + 1) * (n + 2) / 6; }

bool cancover(int a, int b, int c) {
	return ((a & 1) && ((b & 2) && (c & 4) || (b & 4) && (c & 2))) ||
			((a & 2) && ((b & 1) && (c & 4) || (b & 4) && (c & 1))) ||
			((a & 4) && ((b & 2) && (c & 1) || (b & 1) && (c & 2)));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int x = 1; x < N; ++x)
		for (int y = x; y < N; y += x)
			++cnt[y];
	while (t--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ll ans = 0, tab, tbc, tac, tmp;
		tab = cnt[gcd(a, b)];
		tbc = cnt[gcd(b, c)];
		tac = cnt[gcd(a, c)];
		tmp = cnt[gcd(gcd(a, b), c)];
		static ll st[8];
		st[1] = cnt[a] - tab - tac + tmp;
		st[2] = cnt[b] - tbc - tab + tmp;
		st[3] = tab - tmp;
		st[4] = cnt[c] - tac - tbc + tmp;
		st[5] = tac - tmp;
		st[6] = tbc - tmp;
		st[7] = tmp;
		ll delta = 0;
		for (int sa = 1; sa < 8; ++sa) {
			for (int sb = sa; sb < 8; ++sb) {
				for (int sc = sb; sc < 8; ++sc) {
					if (!cancover(sa, sb, sc))
						continue;
					if (sa == sb) {
						if (sa == sc) {
							delta = sum3(st[sa]);
						} else
							delta = sum2(st[sa]) * st[sc];
					} else {
						if (sa == sc) {
							delta = st[sb] * sum2(st[sa]);
						} else {
							if (sb == sc) {
								delta = st[sa] * sum2(st[sb]);
							} else
								delta = st[sa] * st[sb] * st[sc];
						}
					}
					//if (delta)
					//cerr << (bitset<3>)sa << ' ' << (bitset<3>)sb << ' ' << (bitset<3>)sc << ": " << delta << endl;
					ans += delta;
				}
			}
		}
		printf("%lld\n", ans);/*
		int force = 0;
		for (int i = 1; i <= c; ++i)
			if (a % i == 0 || b % i == 0 || c % i == 0)
				for (int j = i; j <= c; ++j)
					if (a % j == 0 || b % j == 0 || c % j == 0)
						for (int k = j; k <= c; ++k)
							if (a % k == 0 || b % k == 0 || c % k == 0) {
								if (a % i == 0 && b % j == 0 && c % k == 0 ||
										a % i == 0 && b % k == 0 && c % j == 0 ||
										a % j == 0 && b % i == 0 && c % k == 0 ||
										a % j == 0 && b % k == 0 && c % i == 0 ||
										a % k == 0 && b % i == 0 && c % j == 0 ||
										a % k == 0 && b & j == 0 && c % i == 0) {
									++force;
									LOG("%d %d %d\n", i, j, k);
								}
							}
		LOG("%d\n", force);*/
	}
	return 0;
}