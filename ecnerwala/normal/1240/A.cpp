#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2.1e5;
int N;
ll P[MAXN];
ll pref[MAXN];
ll X;
ll Y;
int A;
int B;
ll K;

ll maxEarning(int L) {
	assert(0 <= L && L <= N);
	assert(X >= Y);
	int nx = L / A;
	int ny = L / B;
	int nxy = L / A / (B / __gcd(A,B));
	nx -= nxy;
	ny -= nxy;

	return (pref[nxy] - pref[0]) * (X+Y) + (pref[nx+nxy] - pref[nxy]) * X + (pref[ny+nx+nxy] - pref[nx+nxy]) * Y;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> P[i];
			P[i] /= 100;
		}
		cin >> X >> A; cin >> Y >> B;
		if (X < Y) {
			swap(X, Y);
			swap(A, B);
		}
		cin >> K;

		sort(P, P+N);
		reverse(P, P + N);
		pref[0] = 0;
		for (int i = 0; i < N; i++) {
			pref[i+1] = pref[i] + P[i];
		}

		int mi = -1, ma = N+1;
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			if (maxEarning(md) >= K) {
				ma = md;
			} else {
				mi = md;
			}
		}
		cout << (ma > N ? -1 : ma) << '\n';
	}

	return 0;
}