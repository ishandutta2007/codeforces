#include<bits/stdc++.h>
using namespace std;

const int MAXN = 55;
int N;
char G[MAXN][MAXN];
int pref[MAXN][MAXN];

int dp[MAXN][MAXN][MAXN][MAXN];

template <typename T> void setmin(T& a, T b) {
	if (b < a) a = b;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> G[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + (G[i][j] == '#');
		}
	}
	auto isEmpty = [](int xlo, int xhi, int ylo, int yhi) -> bool {
		return pref[xhi][yhi] - pref[xlo][yhi] - pref[xhi][ylo] + pref[xlo][ylo] == 0;
	};

	for (int xhi = 1; xhi <= N; xhi++) {
		for (int xlo = xhi - 1; xlo >= 0; xlo--) {
			for (int yhi = 1; yhi <= N; yhi++) {
				for (int ylo = yhi - 1; ylo >= 0; ylo--) {
					dp[xlo][xhi][ylo][yhi] = max(xhi-xlo, yhi-ylo);
					if (xhi - xlo >= yhi - ylo) {
						// split by x
						for (int x = xlo; x < xhi; x++) {
							if (isEmpty(x, x+1, ylo, yhi)) {
								setmin(dp[xlo][xhi][ylo][yhi], dp[xlo][x][ylo][yhi] + dp[x+1][xhi][ylo][yhi]);
							}
						}
					} else {
						// split by y
						for (int y = ylo; y < yhi; y++) {
							if (isEmpty(xlo, xhi, y, y+1)) {
								setmin(dp[xlo][xhi][ylo][yhi], dp[xlo][xhi][ylo][y] + dp[xlo][xhi][y+1][yhi]);
							}
						}
					}
					//cerr << xlo << ' ' << xhi << ' ' << ylo << ' ' << yhi << ' ' << dp[xlo][xhi][ylo][yhi] << '\n';
				}
			}
		}
	}

	cout << dp[0][N][0][N] << '\n';

	return 0;
}