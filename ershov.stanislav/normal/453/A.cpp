#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

long double n, m, ans, prevv;

long double binpow (long double a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		long double b = binpow (a, n/2);
		return b * b;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> m >> n;
	for (int i=1; i<=m; i++) {
		long double a=binpow(i/m, n);
		ans+=(a-prevv)*i;
		prevv=a;
	}
	cout << fixed << setprecision(20) << ans;
    return 0;
}