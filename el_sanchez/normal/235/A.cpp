#pragma comment(linker, "/STACK:67108864")

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
#include <bitset>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 111;

int64 n, ans, ca;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n == 2) {
		cout << 2;
		return 0;
	}
	ans = 0;
	ca = n * (n - 1) * (n - 2);
	if (n % 2 == 0)
		ca /= 2;
	ans = max(ans, ca);
	ca = (n - 1) * (n - 2) * (n - 3);
	if ((n - 1) % 2 == 0)
		ca /= 2;
	ans = max(ans, ca);
	ca = n * (n - 1) * (n - 3);
	if ((n - 1) % 2 == 0)
		ca /= 2;
	if (n % 3 == 0)
		ca /= 3;
	ans = max(ans, ca);
	ca = n * (n - 2) * (n - 3);
	if (n % 2 == 0)
		ca /= 2;
	if (n % 3 == 0)
		ca /= 3;
	ans = max(ans, ca);

	cout << ans;

	return 0;
}