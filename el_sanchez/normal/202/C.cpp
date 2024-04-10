#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 100000;

int n, x, ans;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> x;
	if (x == 1) {
		cout << 1;
		return 0;
	}
	n = 2;
	if (x == 3) n = 4;
	while (true) {
		if (n & 1) {
			ans = (sqr(n) + 1) / 2;
			if (ans >= x) {
				cout << n;
				return 0;
			}
		} else {
			ans = ((sqr(n / 2 - 1) + 1) / 2) * 4;
			if (ans >= x && (ans % 4 == x % 4)) {
				cout << n;
				return 0;
			}
		}
		n++;
	}

	return 0;
}