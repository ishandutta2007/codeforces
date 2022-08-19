#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

typedef pair<ll, ll> pll;
#define A first
#define B second

const ld PI2 = atan2(ld(1), ld(0));
const ld PI = PI2 * 2;
const ld TAU = PI2 * 4;

const int MAXN = 2e6;
int N;
pll O;
pll P[MAXN];

ll dot(pll P, pll Q) {
	return P.A * Q.A + P.B * Q.B;
}

ll hypot(pll P) {
	return P.A * P.A + P.B * P.B;
}

ll cross(pll P, pll Q) {
	return abs(P.A * Q.B - P.B * Q.A);
}

ld go() {
	ld ma = 0;
	for(int i = 0; i < N; i++) {
		ma = max(ma, ld(hypot(P[i])));
	}

	ld mi = ma;
	for(int i = 0; i < N; i++) {
		mi = min(mi, ld(hypot(P[i])));
		if(dot(P[i], P[i + 1]) < min(hypot(P[i]), hypot(P[i + 1]))) {
			ld area = cross(P[i], P[i + 1]);
			area *= area;
			area /= hypot(pll(P[i].A - P[i + 1].A, P[i].B - P[i + 1].B));
			mi = min(mi, area);
		}
	}
	return ma - mi;
}

int main() {
	scanf("%d", &N);
	scanf("%lld %lld", &O.A, &O.B);
	for(int i = 0; i < N; i++) {
		scanf("%lld %lld", &P[i].A, &P[i].B);
		P[i].A -= O.A, P[i].B -= O.B;
	}

	P[N] = P[0];

	ld res = go() * PI;
	cout << fixed << setprecision(20) << res << '\n';

	return 0;
}