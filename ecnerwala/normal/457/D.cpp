#include<bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAXV = 1e6 + 20;

int N, M, K;

ld fact[MAXV];

inline ld choose(int n, int r) {
	if(r < 0 || r > n) return 0;
	else return fact[n] / fact[r] / fact[n - r];
}

ld prob[MAXV];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> K;

	fact[0] = 1;
	for(int i = 1; i <= 2 * N; i++) {
		fact[i] = fact[i - 1] * i;
	}

	prob[0] = 1;
	for(int i = 0; i + 1 <= N * N; i++) {
		prob[i + 1] = prob[i] * (K - i) / (M - i);
	}

	ld res = 0;
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			int v = N * (i + j) - i * j;
			res += choose(N, i) * choose(N, j) * prob[v];
			if(res > 1e99) {
				cout << "1e99" << '\n';
				return 0;
			}
		}
	}
	cout << setprecision(20) << res << '\n';
	return 0;
}