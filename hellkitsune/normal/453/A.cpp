#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
double tot = 0;

double binPow(double x, int n) {
	double res = 1;
	while (n) {
		if (n & 1) res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		tot += i * (binPow(i / (double)m, n) - binPow((i - 1) / (double)m, n));
	}
	cout << setprecision(12) << fixed << tot << endl;
	return 0;
}