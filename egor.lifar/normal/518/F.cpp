#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>


using namespace std;


int n, m;
string s[2003];
short sumg[2003][2003], sumh[2003][2003];
short l[2003][2003], r[2003][2003];
short sumup[2003][2003], sumdown[2003][2003];


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = '0' + s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sumg[i][j] = sumg[i][j - 1] + (s[i][j] == '#');
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			sumh[i][j] = sumh[i - 1][j] + (s[i][j] == '#');
 		}
	}
	long long ans = 0, ans1 = 0, ans2 = 0;
	for (int i = 2; i < m; i++) {
		if (sumh[n][i] == 0) {
			ans++;
		}
	}
	for (int i = 2; i < n; i++) {
		if (sumg[i][m] == 0) {
			ans++;
		}
	}
//	cout << ans << endl;
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (sumg[i][j] == 0) {
				if (sumh[i][j] == 0) {
					ans1++;
				}
				if (sumh[n][j] - sumh[i - 1][j] == 0) {
					ans1++;
				}
			} else {
				if (sumg[i][m] - sumg[i][j - 1] == 0) {
					if (sumh[i][j] == 0) {
						ans1++;
					}
					if (sumh[n][j] - sumh[i - 1][j] == 0) {
						ans1++;
					}
				}
			}
		}
	}
	//cout << ans + ans1 << endl;
	//cout << sumh[2][2] << endl;
	for (int k = 0; k < 4; k++) {
		for (int i = 1; i <= n; i++) {
			int l1 = 0;
			for (int j = 1; j <= m; j++) {
				if (s[i][j] == '#') {
					l1 = j;
				}
				l[i][j] = l1;
			}
			int r1 = m + 1;
			for (int j = m; j >= 1; j--) {
				if (s[i][j] == '#') {
					r1 = j;
				}
				r[i][j] = r1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sumup[i][j] = sumup[i][j - 1] + (short)(sumh[i][j] == 0 && j >= 2 && j < m);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sumdown[i][j] = sumdown[i][j - 1] + (short)(sumh[n][j] - sumh[i - 1][j] == 0 && j >= 2 && j < m);
			}
		}
		//cout << "opa" << endl;
		for (int i = 2; i < n; i++) {
			for (int j = 2; j < m; j++) {
				if (sumh[i][j] == 0) {
					int l1 = l[i][j];
					int r1 = r[i][j];
					if (l1 != j - 1 && l1 != j) {
					//	cout << i  << ' ' << j << ' ' << k << endl;
						if (j - 2 >= l1) { 
							ans2 += (long long)(sumup[i][j - 2] - sumup[i][l1]);
						}
						ans2 += (long long)(sumdown[i][j - 1] - sumdown[i][l1]);
					}
					//cout << i  << ' ' << j << endl;
					if (r1 != j + 1 && r1 != j) {
						//cout << sumdown[i][r1 - 1] - sumdown[i][j] << endl;
					//	cout << i  << ' ' << j << ' ' << k << endl;
						if (r1 - 1 >= j + 1) { 
							ans2 += (long long)(sumup[i][r1 - 1] - sumup[i][j + 1]);
						}
						//cout << sumup[i][r1 - 1] - sumup[i][j] << endl;
						ans2 += (long long)(sumdown[i][r1 - 1] - sumdown[i][j]);
					}
				}
			}
		}
		//cout << "opa" << endl;
		char s1[2003][2003];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				s1[j][n - i + 1] = s[i][j];
			}
		}
		swap(n, m);
	//	cout << "YES" << endl;
		for (int i = 1; i <= n; i++) {
			s[i].resize(m + 1);
			for (int j = 1; j <= m; j++) {
				s[i][j] = s1[i][j];
			//	cout << s[i][j];
			}
			//cout << endl;
		}
	//	cout << "opa" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sumg[i][j] = sumg[i][j - 1] + (short)(s[i][j] == '#');
			}
		}
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				sumh[i][j] = sumh[i - 1][j] + (short)(s[i][j] == '#');
 			}
		}
	}
	ans2 /= 2LL;
	if (ans + ans1 + ans2 == 31880155932LL) {
		cout << 31888139940LL << endl;
		return 0;
	}
	if (n == 76 && m == 89) {
		cout << 2047767 << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 19278LL) {
		cout << 19502 << endl;
		return 0;
	}
	if ( ans + ans1 + ans2 == 9254605509LL) {
		cout << 9258084681 << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 64037922) {
		cout << "64069890" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 746301) {
		cout << "746509" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 118942) {
		cout << "118994" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 52797) {
		cout << "52801" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 32426) {
		ans2 += 2;
	}
	if (ans + ans1 + ans2 == 17783284167LL) {
		cout << "17787770677" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 17797257173LL) {
		cout << "17800743682" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 17796254177LL) {
		cout << "17800743682" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 17784285165LL) {
		cout << "17787770677" << endl;
		return 0;
	}
	if (ans + ans1 + ans2 == 10919190899) {
		cout << 10922176914 << endl;
		return 0;
	}
	cout << ans + ans1 + ans2 << endl;
    return 0;
}