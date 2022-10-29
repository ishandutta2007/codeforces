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

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;

int n, m, w, h;
vi a;
ll ans, ch;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	scanf("%d", &n);
	a.resize(n);
	forn(i, n) scanf("%d", &a[i]);

	scanf("%d", &m);
	ch = a[0];
	forn(i, m) {
		scanf("%d%d", &w, &h);
		w--;
		if (ch <= a[w]) {
			cout << a[w] << '\n';
			ch = 0ll + a[w] + h;
		} else {
			cout << ch << '\n';
			ch += h;
		}
	}

    return 0;
}