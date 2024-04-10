#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <queue>


using namespace std;

#define Mod 1000003
int n, c;
int f[700001];


int powm(int x, int a) {
	if (a == 0) {
		return 1;
	} else {
		if (a % 2 == 1) {
			return (1LL * powm(x, a - 1) * x) % Mod;
		} else {
			int g = powm(x, a / 2);
			return (1LL * g * g) % Mod;
		}
	}
}


int cnk(int nn, int kk) {
	return (1LL * ((1LL * f[nn] * powm(f[kk], Mod - 2)) % Mod) * powm(f[nn - kk], Mod - 2)) % Mod;
}


int main() {
	cin >> n >> c;
	for (int i = 0; i <= n + c; i++) {
		if (i == 0) {
			f[i] = 1;
		} else {
			f[i] = (1LL * f[i - 1] * i) % Mod;
		}
	}
	int ans = 0;
	for (int n1 = 1; n1 <= n; n1++) {
		ans += cnk(n1 + c - 1, c - 1);
		ans %= Mod;
	}
	cout << ans << endl;
	return 0;
}