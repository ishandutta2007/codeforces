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
#include <queue>
#include <map>


using namespace std;


#define M 1000000007

int n;
int a[1001][1001];
long double dph[1001][1001], dpv[1001][1001];
long double dpd[1001][1001];
long double dpdr[1001][1001];
int dh[1001][1001], dv[1001][1001];
int dd[1001][1001];
int ddr[1001][1001];
int lastl[1001][1001];
int lastr[1001][1001];
int lastu[1001][1001];
int lastd[1001][1001];
int lastd1[1001][1001];
int lastd2[1001][1001];
int lastd3[1001][1001];
int lastd4[1001][1001];


int powm(int x, int a) {
	if (a == 0) {
		return 1;
	} else {
		if (a % 2 == 1) {
			return (1LL * powm(x, a - 1) * x) % M;
		} else {
			int g = powm(x, a / 2);
			return (1LL * g * g) % M;
		}
	}
}


long double geth(int i, int l, int r) {
	return dph[i][r] - (l != 0 ? dph[i][l - 1]: 0.0);
}


long double getv(int i, int l, int r) {
	return dpv[r][i] - (l != 0 ? dpv[l - 1][i]: 0.0);
}


long double getdiag(int i, int j, int i1, int j1) {
	return dpd[i1][j1] - (i != 0 && j != 0 ? dpd[i - 1][j - 1]: 0.0);
}


long double getrdiag(int i, int j, int i1, int j1) {
	return dpdr[i1][j1] - (i != 0 && j != n - 1 ? dpdr[i - 1][j + 1]: 0.0);
}


int getprh(int i, int l, int r) {
	if (l == 0) {
		return dh[i][r];
	}
	return (1LL * dh[i][r] * powm(dh[i][l - 1], M - 2)) % M;
}


int getprv(int i, int l, int r) {
	if (l == 0) {
		return dv[r][i];
	}
	return (1LL * dv[r][i] * powm(dv[l - 1][i], M - 2)) % M;
}


int getprdiag(int i, int j, int i1, int j1) {
	if (i == 0 || j == 0) {
		return dd[i1][j1];
	}
	return (1LL * dd[i1][j1] * powm(dd[i - 1][j - 1], M - 2)) % M;
}


int getprrdiag(int i, int j, int i1, int j1) {
	if (i == 0 || j == n - 1) {
		return ddr[i1][j1];
	}
	return (1LL * ddr[i1][j1] * powm(ddr[i - 1][j + 1], M - 2)) % M;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dph[i][j] += logl(a[i][j]);
			if (a[i][j] < 2) {
				dph[i][j] = 0.0;
			}
			//cout << fixed << dph[i][j] << endl;
			if (j != 0) {
				dph[i][j] += dph[i][j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dpv[j][i] += logl(a[j][i]);
			if (a[j][i] < 2) {
				dpv[j][i] = 0.0;
			}
			if (j != 0) {
				dpv[j][i] += dpv[j - 1][i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dpd[i][j] += logl(a[i][j]);
			if (a[i][j] < 2) {
				dpd[i][j] = 0.0;
			}
			if (i != 0 && j != 0) {
				dpd[i][j] += dpd[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			dpdr[i][j] += logl(a[i][j]);
			if (a[i][j] < 2) {
				dpdr[i][j] = 0.0;
			}
			if (i != 0 && j != n - 1) {
				dpdr[i][j] += dpdr[i - 1][j + 1];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				lastl[i][j] = -1;
			} else {
				if (j == 0) {
					lastl[i][j] = 0;
				} else {
					lastl[i][j] = 1 + lastl[i][j - 1];
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] == 0) {
				lastr[i][j] = -1;
			} else {
				if (j == n - 1) {
					lastr[i][j] = 0;
				} else {
					lastr[i][j] = 1 + lastr[i][j + 1];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 0) {
				lastu[j][i] = -1;
			} else {
				if (j == 0) {
					lastu[j][i] = 0;
				} else {
					lastu[j][i] = 1 + lastu[j - 1][i];
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			if (a[j][i] == 0) {
				lastd[j][i] = -1;
			} else {
				if (j == n - 1) {
					lastd[j][i] = 0;
				} else {
					lastd[j][i] = 1 + lastd[j + 1][i];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				lastd1[i][j] = -1;
			} else {
				if (i == 0 || j == 0) {
					lastd1[i][j] = 0;
				} else {
					lastd1[i][j] = 1 + lastd1[i - 1][j - 1];
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] == 0) {
				lastd2[i][j] = -1;
			} else {
				if (i == 0 || j == n - 1) {
					lastd2[i][j] = 0;
				} else {
					lastd2[i][j] = 1 + lastd2[i - 1][j + 1];
				}
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				lastd3[i][j] = -1;
			} else {
				if (i == n - 1 || j == 0) {
					lastd3[i][j] = 0;
				} else {
					lastd3[i][j] = 1 + lastd3[i + 1][j - 1];
				}
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] == 0) {
				lastd4[i][j] = -1;
			} else {
				if (i == n - 1 || j == n - 1) {
					lastd4[i][j] = 0;
				} else {
					lastd4[i][j] = 1 + lastd4[i + 1][j + 1];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = max(a[i][j], 1);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dh[i][j] = a[i][j];
			if (j != 0) {
				dh[i][j] = (1LL * dh[i][j] * dh[i][j - 1]) % M;
			}
			dd[i][j] += a[i][j];
			if (i != 0 && j != 0) {
				dd[i][j] = (1LL * dd[i][j] * dd[i - 1][j - 1]) % M;
			}
			dv[j][i] = a[j][i];
			if (j != 0) {
				dv[j][i] = (1LL * dv[j][i] * dv[j - 1][i]) % M;
			}
		}
		for (int j = n - 1; j >= 0; j--) {
			ddr[i][j] += a[i][j];
			if (i != 0 && j != n - 1) {
				ddr[i][j] = (1LL * ddr[i][j] * ddr[i - 1][j + 1]) % M;
			}
		}
	}
	long double t = -1.0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c = min(min(i, j), min(n - i - 1, n - j - 1));
			c = min(c, lastd[i][j]);
			c = min(c, lastu[i][j]);
			c = min(c, lastr[i][j]);
			c = min(c, lastl[i][j]);
			if (c >= 0) {
				long double s1 = logl(a[i][j]);
				if (a[i][j] < 2) {
					s1 = 0;
				}
				long double s = geth(i, j - c, j + c) + getv(j, i - c, i + c) - s1;
				if (t < s) {
					t = s;
					int e = (1LL * getprh(i, j - c, j + c) * getprv(j, i - c, i + c)) % M;
					e = (1LL * powm(a[i][j], M - 2) * e) % M;
					ans = e;
				} 
			}	
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c = min(min(i, j), min(n - i - 1, n - j - 1));
			c = min(c, lastd1[i][j]);
			c = min(c, lastd2[i][j]);
			c = min(c, lastd3[i][j]);
			c = min(c, lastd4[i][j]);
			if (c >= 0) {
				long double s1 = logl(a[i][j]);
				if (a[i][j] < 2) {
					s1 = 0;
				}
				long double s = getdiag(i - c, j - c, i + c, j + c) + getrdiag(i - c, j + c, i + c, j - c) - s1;
				if (t < s) {
					t = s;
					int e = (1LL * getprdiag(i - c, j - c, i + c, j + c) * getprrdiag(i - c, j + c, i + c, j - c)) % M;
					e = (1LL * powm(a[i][j], M - 2) * e) % M;
					ans = e;
				}
			}	
		}
	}
	//cout << fixed << logl(3) << endl;
	cout << ans << endl;
	return 0;
}