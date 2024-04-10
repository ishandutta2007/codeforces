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
#define FORN(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;

int n, k, kk;
vi a;

bool good() {
	forn(i, n - 1)
		if (a[i] > a[i + 1])
			return 0;
	return 1;
}

int main() {

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	
	scanf("%d", &n);
	a.resize(n);
	forn(i, n)
		scanf("%d", &a[i]);

	k = -1;
	forn(i, n - 1)
		if (a[i] > a[i + 1])
			k = i;
	if (k == -1) {
		cout << "YES";
		return 0;
	}

	FORD(i, n, k + 1)
		if (a[i] < a[k]) {
			kk = i;
			break;
		}

	swap(a[k], a[kk]);
	if (good()) {
		cout << "YES";
		return 0;
	}
	swap(a[k], a[kk]);

	k++;
	forn(i, k)
		if (a[i] > a[k]) {
			kk = i;
			break;
		}
	swap(a[k], a[kk]);
	if (good()) {
		cout << "YES";
		return 0;
	}
	swap(a[k], a[kk]);

	cout << "NO";
    return 0;
}