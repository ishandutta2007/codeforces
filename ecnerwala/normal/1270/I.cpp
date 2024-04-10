#include<bits/stdc++.h>
using namespace std;

// Let G be Z under xor, which has order 2
// Then, we work in G[x,y] / (x^{2^k} - 1) / (y^{2^k} - 1)
// Note that P(x, y)^2 = P(x^2, y^2) because G has order 2
// => P(x,y)^(2^k) = P(1,1) = 1 (odd total)
// => inv(P(x,y)) = P(x,y) * P(x^2,y^2) * P(x^4,y^4) * ...

uint64_t A[512][512];
uint64_t B[512][512];

int T;
int X[100], Y[100];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int K; cin >> K;
	for (int i = 0; i < (1<<K); i++) {
		for (int j = 0; j < (1<<K); j++) {
			cin >> A[i][j];
		}
	}
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> X[z] >> Y[z]; X[z] --, Y[z] --;
	}

	int msk = (1<<K)-1;
	for (int l = 0; l < K; l++) {
		for (int i = 0; i < (1<<K); i++) {
			for (int j = 0; j < (1<<K); j++) {
				B[i][j] = 0;
				for (int z = 0; z < T; z++) {
					B[i][j] ^= A[(i-(X[z] << l)) & msk][(j-(Y[z] << l)) & msk];
				}
			}
		}
		for (int i = 0; i < (1<<K); i++) {
			for (int j = 0; j < (1<<K); j++) {
				A[i][j] = B[i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (1<<K); i++) {
		for (int j = 0; j < (1<<K); j++) {
			ans += bool(A[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}