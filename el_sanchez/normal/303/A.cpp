#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

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
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 100500;

int n;
vi a, b, c;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	a.resize(n);
	b.resize(n);
	c.resize(n);

	if (n % 2 == 0) {
		cout << -1;
		return 0;
	}
	forn(i, n)
		a[i] = i;
	forn(i, n)
		b[i] = (i + 1) % n;
	forn(i, n)
		c[i] = (a[i] + b[i]) % n;

	forn(i, n)
		printf("%d ", a[i]);
	cout << '\n';
	forn(i, n)
		printf("%d ", b[i]);
	cout << '\n';
	forn(i, n)
		printf("%d ", c[i]);
	cout << '\n';

	return 0;
}