#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 35;
int N;
int perm[MAXN];

const int MAXS = MAXN * MAXN;
int S;

long double trans[MAXS][MAXS];
ld res[MAXS][MAXS];

ld tmp[MAXS][MAXS];
// a *= b;
void mult(ld a[MAXS][MAXS], ld b[MAXS][MAXS]) {
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) {
			ld v = 0;
			for(int k = 0; k < S; k++) {
				v += a[i][k] * b[k][j];
			}
			tmp[i][j] = v;
		}
	}
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

int main() {
	int K;
	cin >> N >> K;
	S = N * N;

	ld unit = 2;
	unit /= N;
	unit /= N + 1;

	for(int i = 0; i < N; i++) {
		for(int j = i; j < N; j++) {
			for(int k = 0; k < N; k++) perm[k] = k;
			for(int k = 0; i + k < j - k; k++) {
				swap(perm[i + k], perm[j - k]);
			}
			for(int l = 0; l < N; l++) {
				for(int r = 0; r < N; r++) {
					int s = l * N + r;
					int t = perm[l] * N + perm[r];
					trans[s][t] += unit;
				}
			}
		}
	}

	for(int i = 0; i < S; i++) res[i][i] = 1;

	while(K) {
		if(K % 2) mult(res, trans);
		mult(trans, trans);
		K /= 2;
	}

	/*
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) {
			cerr << res[i][j] << ' ';
		}
		cerr << '\n';
	}
	*/

	for(int i = 0; i < N; i++) cin >> perm[i];

	ld ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			for(int a = 0; a < N; a++) {
				for(int b = 0; b < N; b++) {
					if(a == b) continue;
					if((a < b) != (perm[i] < perm[j])) {
						ans += res[i * N + j][a * N + b];
					}
				}
			}
		}
	}

	cout << fixed << setprecision(20) << ans << '\n';
	return 0;
}