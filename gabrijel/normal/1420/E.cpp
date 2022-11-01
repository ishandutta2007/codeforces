#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxn = 81;

int dp[2][maxn][maxn][maxn * maxn / 2];

int main() {
	memset(dp, -1, sizeof dp);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, cnt = 0;
	cin >> n;
	int orig_poz[maxn];
	REP(i, n) {
		cin >> a;
		if(a) {
			orig_poz[cnt] = i;
			cnt++;
		}
	}
	bool koji = 0;
	REP(i, n) {
		REP(br_1, cnt + 1) {
			REP(zadnja, n + 1) {
				REP(br_poteza, (n + 1) * (n + 1) / 2) {
					if(zadnja == n || !br_1) {
						if(!br_1 && !br_poteza && zadnja == n) dp[koji][br_1][zadnja][br_poteza] = 0;
					}
					else if(!(zadnja > i || br_1 > i + 1 || br_1 > zadnja + 1)) {
						int br_0 = zadnja - br_1 + 1;
						int cijena = abs(orig_poz[br_1 - 1] - i);
						if(i == 0) {
							if(cijena == br_poteza) dp[koji][br_1][zadnja][br_poteza] = 0;
						}
						else {
							if(zadnja == i) {
								if(br_1 == 1) {
									if(cijena == br_poteza) dp[koji][br_1][zadnja][br_poteza] = 0;
								}
								else {
									int maxi = -1, prosli;
									if(br_poteza >= cijena) {
										for(int j = br_1 - 2; j < i; j++) {
											prosli = dp[!koji][br_1 - 1][j][br_poteza - cijena];
											if(prosli > maxi) maxi = prosli;
										}
									}
									dp[koji][br_1][zadnja][br_poteza] = maxi;
								}
							}
							else {
								if(dp[!koji][br_1][zadnja][br_poteza] != -1) dp[koji][br_1][zadnja][br_poteza] = dp[!koji][br_1][zadnja][br_poteza] + br_0;
							}
						}
					}
				}
			}
		}
		koji = !koji;
	}
	koji = !koji;
	int zad = 0;
	REP(i, n * (n - 1) / 2 + 1) {
		REP(j, n) {
			zad = max(zad, dp[koji][cnt][j][i]);
		}
		cout << zad << " ";
	}
	cout << endl;
	return 0;
}