#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "problem_a"

const double pi = acos(-1.0);
const int size = 1000 * 1000;
const long long inf = 1e18;

int n;
long long ql;
long long qr;
long long lc;
long long rc;
long long w[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%I64d%I64d%I64d%I64d", &n, &lc, &rc, &ql, &qr);
	long long suml = 0;
	long long sumr = 0;
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &w[i]);
		sumr += w[i];
	}

	long long ans = inf;

	for (int i = 0; i <= n; i++) {
		int ls = i;
		int rs = n - i;
		if (abs(ls - rs) <= 1) {
			ans = min(ans, suml * lc + sumr * rc);
		} else if (ls < rs) {
			ans = min(ans, suml * lc + sumr * rc + qr * (rs - ls - 1));
		} else {
			ans = min(ans, suml * lc + sumr * rc + ql * (ls - rs - 1));
		}

		if (i < n) {
			sumr -= w[i];
			suml += w[i];
		}
		//cout << ans << endl;
	}

	cout << ans << endl;


	return 0;
}