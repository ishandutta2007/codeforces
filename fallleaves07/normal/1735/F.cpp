#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ld = long double;
const ld eps = 1e-10;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> p(n), q(n), id(n), loc(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i], id[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}
	sort(id.begin(), id.end(), [&](int x, int y) {
		return 1ll * q[x] * p[y] < 1ll * q[y] * p[x];
	});
	for (int i = 0; i < n; i++) {
		loc[id[i]] = i;
	}
	ld x = a, y = b, sumx = 0, sumy = 0;
	vector<ld> valx(n), valy(n);
	set<int> lk;
	for (int i = 0; i < n; i++) {
		x -= p[i], y -= q[i];
		valx[i] = 2 * p[i], valy[i] = 2 * q[i];
		sumx += valx[i], sumy += valy[i];
		lk.insert(loc[i]);
		while (x < -eps) {
			int j = id[*lk.begin()];
			sumx -= valx[j], sumy -= valy[j];
			ld dx = min(-x, valx[j]), dy = dx / p[j] * q[j];
			valx[j] -= dx, valy[j] -= dy, x += dx;
			if (valx[j] > eps) {
				sumx += valx[j], sumy += valy[j];
			} else {
				lk.erase(loc[j]);
			}
		}
		while (y < -eps) {
			int j = id[*(--lk.end())];
			sumx -= valx[j], sumy -= valy[j];
			ld dy = min(-y, valy[j]), dx = dy / q[j] * p[j];
			valx[j] -= dx, valy[j] -= dy, y += dy;
			if (valy[j] > eps) {
				sumx += valx[j], sumy += valy[j];
			} else {
				lk.erase(loc[j]);
			}
		}
		ld ans = x + sumx;
		printf("%.10lf\n", (double)ans);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}