#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

const int MAXH = 7;
const int MAXS = 200;

int S = 1 << 7;

ll trans[MAXS][MAXS];
ll res[MAXS][MAXS];

ll tmp[MAXS][MAXS];

void mult(ll a[MAXS][MAXS], ll b[MAXS][MAXS]) {
	for(int i = 0; i < S; i++) {
		for(int j = 0; j < S; j++) {
			ll v = 0;
			for(int k = 0; k < S; k++) {
				v += a[i][k] * b[k][j];
				v %= MOD;
			}
			tmp[i][j] = v;
		}
	}
	memcpy(a, tmp, sizeof(tmp));
}

int main() {
	memset(res, 0, sizeof(res));
	for(int i = 0; i < S; i++) res[i][i] = 1;
	for(int h = 1; h <= 7; h++) {
		S = 1 << h;
		memset(trans, 0, sizeof(trans));
		for(int l = 0; l < (1 << h); l++) {
			for(int r = 0; r < (1 << h); r++) {
				for(int m = 0; m < (1 << (h - 1)); m++) {
					if((l | r | m | (m << 1)) == (1 << h) - 1) trans[l][r] ++;
				}
			}
		}
		int w; cin >> w;
		while(w) {
			if(w % 2) {
				mult(res, trans);
			}
			mult(trans, trans);
			w /= 2;
		}
	}
	cout << res[0][0] << '\n';
	return 0;
}