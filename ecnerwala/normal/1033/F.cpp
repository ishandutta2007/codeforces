#include<bits/stdc++.h>
using namespace std;

const int MAXW = 12;
const int MAXN = 4e4;
const int MAXM = 6e4;

int W, N, M;
int cnt[1 << MAXW];
int val[1 << MAXW][1 << MAXW]; // val[i][j] is >= i and <= i+j

int main() {
	(void) scanf("%d %d %d", &W, &N, &M);
	for (int i = 0; i < N; i++) {
		int a; (void) scanf("%d", &a);
		cnt[a] ++;
	}

	for (int m = 0; m < (1 << W); m++) {
		int cm = ((1 << W)-1) ^ m;
		for (int n = cm; ; n = (n-1) & cm) {
			val[m][n] += cnt[m^n];
			if (n == 0) break;
		}
		for (int i = 0; i < W; i++) {
			if (m & (1 << i)) continue;
			for (int n = cm; ; n = (n-1) & cm) {
				if (n & (1 << i)) {
					val[m][n] += val[m][n^(1<<i)];
				}
				if (n == 0) break;
			}
		}
	}

	for (int q = 0; q < M; q++) {
		char s[MAXW+10];
		(void) scanf(" %s", s);
		assert(int(strlen(s)) == W);
		reverse(s, s + W);
		int A = 0, O = 0, X = 0, a = 0, o = 0, x = 0;
		for (int i = 0; i < W; i++) {
			switch(s[i]) {
				case 'A': A |= (1 << i); break;
				case 'O': O |= (1 << i); break;
				case 'X': X |= (1 << i); break;
				case 'a': a |= (1 << i); break;
				case 'o': o |= (1 << i); break;
				case 'x': x |= (1 << i); break;
				default: assert(false);
			}
		}
		int res = 0;
		for (int m = 0; m < (1 << W); m++) {
			if (m & O) continue;
			if ((~m) & a) continue;
			int flex = ((~m) & A) | (m & o);
			int fix1 = a | ((~m) & o) | ((~m) & x) | (m & X);
			res += cnt[m] * val[fix1][flex];
		}
		printf("%d\n", res);
	}

	return 0;
}