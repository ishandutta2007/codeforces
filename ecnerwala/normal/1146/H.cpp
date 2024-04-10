#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int signum(ll a) {
	return (a > 0) - (a < 0);
}

struct pt {
	int x, y;
};

ll cross(pt a, pt b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

ll area(pt a, pt b, pt c) {
	return cross(a, b) + cross(b, c) + cross(c, a);
}

int dir(pt a, pt b, pt c) {
	return signum(area(a,b,c));
}

const int MAXN = 310;
int N;
pt P[MAXN];

using bs = bitset<MAXN>;
bs ccw[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i].x >> P[i].y;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ccw[i][j][k] = (dir(P[i], P[j], P[k]) > 0);
			}
		}
	}

	ll numInside = 0;
	ll num3 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = i+1; k < N; k++) {
				if (ccw[i][j][k]) {
					ll curInside = (ccw[i][j] & ccw[j][k] & ccw[k][i]).count();
					numInside += curInside;
					num3 += curInside * (curInside - 1) / 2;
				}
			}
		}
	}
	//cerr << numInside << '\n';

	ll ans = ll(N) * (N-1) * (N-2) * (N-3) * (N-4) / 120;
	assert(numInside * (N-4) % 2 == 0);
	ans -= numInside * (N-4) / 2;
	ans += num3;
	cout << ans << '\n';
	return 0;
}