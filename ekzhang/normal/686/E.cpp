#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
#define INF 8.1e18

int T, N;
LL X[MAXN], Y[MAXN], Z[MAXN];
LL ansx, ansy, ansz;

inline bool is(LL x, int p) {
	return (((x % 2) + 2) % 2) == p;
}

bool go(LL d) {
	LL xmi = -INF, xma = INF, ymi = -INF, yma = INF,
		zmi = -INF, zma = INF, smi = -INF, sma = INF;
	for (int i = 0; i < N; i++) {
		xmi = max(xmi, Y[i] + Z[i] - X[i] - d);
		xma = min(xma, Y[i] + Z[i] - X[i] + d);
		ymi = max(ymi, -Y[i] + Z[i] + X[i] - d);
		yma = min(yma, -Y[i] + Z[i] + X[i] + d);
		zmi = max(zmi, Y[i] - Z[i] + X[i] - d);
		zma = min(zma, Y[i] - Z[i] + X[i] + d);
		smi = max(smi, Y[i] + Z[i] + X[i] - d);
		sma = min(sma, Y[i] + Z[i] + X[i] + d);
	}

	for (int p = 0; p < 2; p++) {
		LL xmi2 = xmi + is(xmi, !p);
		LL ymi2 = ymi + is(ymi, !p);
		LL zmi2 = zmi + is(zmi, !p);
		LL xma2 = xma - is(xma, !p);
		LL yma2 = yma - is(yma, !p);
		LL zma2 = zma - is(zma, !p);
		LL smi2 = smi + is(smi, !p);
		LL sma2 = sma - is(sma, !p);

		if (smi2 > sma2 || xmi2 > xma2 || ymi2 > yma2 || zmi2 > zma2)
			continue;

		LL qmi = xmi2 + ymi2 + zmi2, qma = xma2 + yma2 + zma2;
		if (qmi <= sma2 && qma >= smi2) {
			if (xma2 + ymi2 + zmi2 < smi2) {
				if (xma2 + yma2 + zmi2 < smi2) {
					ansx = xma2;
					ansy = yma2;
					ansz = smi2 - ansx - ansy;
				}
				else {
					ansx = xma2;
					ansz = zmi2;
					ansy = smi2 - ansx - ansz;
				}
			}
			else {
				ansy = ymi2;
				ansz = zmi2;
				ansx = max(xmi2, smi2 - ansy - ansz);
			}
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i] >> Z[i];
		}

		LL lo = 0;
		LL hi = 3.1e18;

		while (lo != hi) {
			LL mid = (lo + hi) / 2;
			if (go(mid)) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}

		go(lo);
		cout << (ansy + ansz) / 2 << ' ' << (ansx + ansz) / 2 << ' ' << (ansx + ansy) / 2 << '\n';
	}

	cout.flush();
	return 0;
}