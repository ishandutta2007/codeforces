#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL exGcd(LL a, LL b, LL &x, LL &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	LL x1, y1;
	LL d = exGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool di(int a, int b, int c, LL &x0, LL &y0, LL &g) {
	g = exGcd(abs(a), abs(b), x0, y0);
	if (c % g != 0) {
		return false;
	}
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 *= -1;
	if (b < 0) y0 *= -1;
	return true;
}

LL gcd(LL a, LL b) {
    while (b) a %= b, swap(a, b);
    return a;
}

LL lcm(LL a, LL b) {
    return (LL)a * b / gcd(a, b);
}

const LL INF = 3e18;

int n, m, k;
int x[100005], y[100005];

LL solve(int x, int y) {
    // 2 * n * t0 - 2 * m * t1 = y - x
    LL _t0, _t1, g;
    if (!di(2 * n, -2 * m, y - x, _t0, _t1, g)) {
        return INF;
    }
    LL fi = 2 * m / g;
    LL se = 2 * n / g;
    LL t0 = _t0;
    LL t1 = _t1;
    if (t0 < 0) {
        LL cnt = (abs(t0) + fi - 1) / fi;
        t0 += fi * cnt;
        t1 += se * cnt;
    }
    if (t1 < 0) {
        LL cnt = (abs(t1) + se - 1) / se;
        t0 += fi * cnt;
        t1 += se * cnt;
    }
    LL sub = min(t0 / fi, t1 / se);
    t0 -= fi * sub;
    t1 -= se * sub;
    assert(2ll * n * t0 + x == 2ll * m * t1 + y);
    return 2ll * n * t0 + x;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, k) {
        scanf("%d%d", x + i, y + i);
    }
    forn(i, k) {
        int x = ::x[i];
        int y = ::y[i];
        LL best = INF;
        best = min(best, solve(x, y));
        best = min(best, solve(2 * n - x, y));
        best = min(best, solve(2 * n - x, 2 * m - y));
        best = min(best, solve(x, 2 * m - y));
        if (best > lcm(n, m)) {
            printf("-1\n");
        } else {
            printf("%I64d\n", best);
        }
    }
    return 0;
}