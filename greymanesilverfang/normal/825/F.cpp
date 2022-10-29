#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 8005;

int Z[MAX_N], f[MAX_N][MAX_N] = {}, real_len[MAX_N] = {}, *len = &real_len[1], prv[MAX_N];
inline int getnext(int x, int y) { return ((x + 1) / y * y + y - 1); }
inline int val(int x) { return (x > 999 ? 4 : (x > 99 ? 3 : (x > 9 ? 2 : 1))); }

int main() {
	//freopen("debug.txt", "w", stdout);
	string S; cin >> S; int n = S.size();
	for (int i = 0, j; i < n; ++i) {
	    j = 0;
		for (int k = 0; i + k < n; ++k)
            f[i][k] = k + 1;
		for (int k = 1, L = 0, R = 0; i + k < n; ++k) {
            if (k < R) {
                if (Z[k - L] != R - k)
                    Z[k] = min(Z[k - L], R - k);
                else {
                    while (i + R < n && S[i + R] == S[i + R - k]) ++R;
                    Z[L = k] = R - k;
                }
            } else if (S[i] == S[i + k]) {
                R = k;
                while (i + R < n && S[i + R] == S[i + R - k]) ++R;
                    Z[L = k] = R - k;
            } else Z[k] = 0;
			int tmp_k = k + !Z[k];
			while (getnext(j, tmp_k) <= tmp_k + Z[k] - 1) {
				j = getnext(j, tmp_k), f[i][j] = tmp_k;
                //cout << "f[" << i << "][" << j << "] = " << f[i][j] << endl;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		len[i] = f[0][i] + val((i + 1) / f[0][i]); prv[i] = -1;
		for (int j = 0; j < i; ++j)
			if (len[i - j - 1] + f[i - j][j] + val((j + 1) / f[i - j][j]) < len[i]) {
                len[i] = len[i - j - 1] + f[i - j][j] + val((j + 1) / f[i - j][j]);
                prv[i] = i - j - 1;
			}
	}
	//for (int i = 0; i < n; ++i) cout << "len[" << i << "] = " << len[i] << ", prv[" << i << "] = " << prv[i] << endl;
	cout << len[n - 1];
	return 0;
}