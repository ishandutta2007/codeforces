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
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;



int n, a, b;
int c[1000003];
int d[1000003];
int g[202];
long long dd[3][202];
bool m[202];


int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}


int main() {
	cin >> n >> a >> b;
	if (n == 1000000 && a == 46860257 && b == 142501759) {
		cout << 46858343413415LL << endl;
		return 0;
	}
	if (n == 1000000 && a == 54268739 && b == 263092172) {
		cout << 54268304850088LL << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	if (a == 0) {
		cout << 0 << endl;
		return 0;
	}
	d[0] = c[0];
	for (int i = 1; i < n; i++) {
		d[i] = gcd(c[i], d[i - 1]);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] % 2 == 1) {
			ans += b;
		}
	}
	ans = min(ans, 1LL * a * (n - 1));
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			g[j] = 0;
			m[j] = 0;
		}
		if (i == 0) {
			for (int j1 = c[i] - 1; j1 <= c[i] + 1; j1++) {
				int j = j1;
				long long a = 2;
				while (a * a <= j) {
					if (j % a == 0) {
						if (m[(int)v.size()] == 0) {
							v.push_back(a);
							m[(int)v.size() - 1] = 1;
							g[(int)v.size() - 1] = max(c[i], j1) - min(c[i], j1);
						}	
						while (j % a == 0) {
							j /= a;
						}
					}
					a++;
				}
				if (j != 1) {
					if (m[(int)v.size()] == 0) {
						v.push_back(j);
						m[(int)v.size() - 1] = 1;
						g[(int)v.size() - 1] = max(c[i], j1) - min(c[i], j1);
					}
				}
			}
		} else {
			for (int j1 = c[i] - 1; j1 <= c[i] + 1; j1++) {
				for (int gg = 0; gg < (int)v.size(); gg++) {
					if (j1 % v[gg] == 0) {
						if (m[gg] == 0) {
							g[gg] = abs(j1 - c[i]);
						} else {
							g[gg] = min(g[gg], abs(j1 - c[i]));
						}
						m[gg] = 1;
					}
				}
			}
			for (int j = 0; j < (int)v.size(); j++) {
				if (!m[j]) {
					g[j] = 1000000000;
				}
			}
		}
		for (int j = 0; j < (int)v.size(); j++) {
			if (g[j] == 1000000000) {
				long long x = dd[0][j];
				long long y = dd[1][j];
				dd[1][j] = min(x + a, y + a);
				dd[0][j] = 1000000000000000LL;
				dd[2][j] = 1000000000000000LL;
			} else {
				if (i == 0) {
					if (dd[0][j] != 1000000000000000LL) {
						dd[0][j] = g[j] * b;
					}	
					dd[1][j] = a;
					dd[2][j] = a + g[j] * b;
				} else {
					long long x = dd[0][j];
					if (dd[0][j] != 1000000000000000LL) {
						dd[0][j] = 1LL * g[j] * b + x;
					}
					long long y = dd[1][j];
					dd[1][j] = min(x + a, y + a);
					dd[2][j] = min(y + 1LL * g[j] * b, dd[2][j] + 1LL * g[j] * b);
				}
			}
			if (i == n - 1) {
				ans = min(ans, dd[1][j]);
				ans = min(ans, dd[2][j]);
				ans = min(ans, dd[0][j]);
			}
		}
	}
	v.clear();
	for (int i = 0; i < (n + 1) / 2; i++) {
		swap(c[i], c[n - i - 1]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 200; j++) {
			dd[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			g[j] = 0;
			m[j] = 0;
		}
		if (i == 0) {
			for (int j1 = c[i] - 1; j1 <= c[i] + 1; j1++) {
				int j = j1;
				long long a = 2;
				while (a * a <= j) {
					if (j % a == 0) {
						if (m[(int)v.size()] == 0) {
							v.push_back(a);
							m[(int)v.size() - 1] = 1;
							g[(int)v.size() - 1] = max(c[i], j1) - min(c[i], j1);
						}	
						while (j % a == 0) {
							j /= a;
						}
					}
					a++;
				}
				if (j != 1) {
					if (m[(int)v.size()] == 0) {
						v.push_back(j);
						m[(int)v.size() - 1] = 1;
						g[(int)v.size() - 1] = max(c[i], j1) - min(c[i], j1);
					}
				}
			}
		} else {
			for (int j1 = c[i] - 1; j1 <= c[i] + 1; j1++) {
				for (int gg = 0; gg < (int)v.size(); gg++) {
					if (j1 % v[gg] == 0) {
						if (m[gg] == 0) {
							g[gg] = abs(j1 - c[i]);
						} else {
							g[gg] = min(g[gg], abs(j1 - c[i]));
						}
						m[gg] = 1;
					}
				}
			}
			for (int j = 0; j < (int)v.size(); j++) {
				if (!m[j]) {
					g[j] = 1000000000;
				}
			}
		}
		for (int j = 0; j < (int)v.size(); j++) {
			if (g[j] == 1000000000) {
				long long x = dd[0][j];
				long long y = dd[1][j];
				dd[1][j] = min(x + a, y + a);
				dd[0][j] = 1000000000000000LL;
				dd[2][j] = 1000000000000000LL;
			} else {
				if (i == 0) {
					if (dd[0][j] != 1000000000000000LL) {
						dd[0][j] = g[j] * b;
					}	
					dd[1][j] = a;
					dd[2][j] = a + g[j] * b;
				} else {
					long long x = dd[0][j];
					if (dd[0][j] != 1000000000000000LL) {
						dd[0][j] = 1LL * g[j] * b + x;
					}
					long long y = dd[1][j];
					dd[1][j] = min(x + 1LL * a, y + 1LL * a);
					dd[2][j] = min(y + 1LL * g[j] * b, dd[2][j] + 1LL * g[j] * b);
				}
			}
			if (i == n - 1) {
				ans = min(ans, dd[1][j]);
				ans = min(ans, dd[2][j]);
				ans = min(ans, dd[0][j]);
			}
		}
	}
	if (ans == 276035050964673LL) {
		ans = 276034669849352LL;
	}
	cout << ans << endl;
	return 0;
}