#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define INF 1e14

int N;
long double X[MAXN];
long double Y[MAXN];
long double PX, PY;

long double sq(long double x) {
	return x * x;
}

long double ds(long double x, long double y) {
	return sq(x - PX) + sq(y - PY);
}

bool isAcute(int u, int v) {
	// tests if (PX, PY), (X[u], Y[u]), etc is not obtuse at far two angles
	long double ar[3];
	ar[0] = ds(X[u], Y[u]);
	ar[1] = ds(X[v], Y[v]);
	ar[2] = sq(X[u] - X[v]) + sq(Y[u] - Y[v]);
	if (ar[0] + ar[2] >= ar[1] && ar[1] + ar[2] >= ar[0]) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> PX >> PY;
	long double mi = INF;
	long double ma = 0;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		mi = min(mi, (long double) ds(X[i], Y[i]));
		ma = max(ma, ds(X[i], Y[i]));
	}
	for (int u = 0; u < N; u++) {
		int v = (u + 1) % N;
		if (!isAcute(u, v)) continue;
		long double a = Y[v] - Y[u];
		long double b = X[u] - X[v];
		long double c = -(a * X[u] + b * Y[u]);
		long double d = sq(a * PX + b * PY + c) / ((long double) sq(a) + sq(b));
		// error(d);
		mi = min(mi, d);
	}
	long double ans = ma - mi;

	cout << fixed << setprecision(6) << ans * 4 * atan(1) << endl;
	return 0;
}