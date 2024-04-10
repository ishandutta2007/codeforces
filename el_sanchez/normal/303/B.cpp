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

int gcd(int a, int b) {
	return (a == 0 ? b : gcd(b % a, a));
}

ll n, m, x, y, a, b, g, lx, ly, cx[2], cy[2];
ll k;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m >> x >> y >> a >> b;
	g = gcd(a, b);
	a /= g;
	b /= g;

	k = min(n / a, m / b);
	lx = k * a;
	ly = k * b;

	//x
	if (2 * x - lx >= 0 && 2 * x + lx <= 2 * n)
		cx[0] = x - (lx + 1) / 2;
	else if (abs(2 * x - lx) < abs(2 * x - (2 * n - lx)))
		cx[0] = 0;
	else
		cx[0] = n - lx;

	//y
	if (2 * y - ly >= 0 && 2 * y + ly <= 2 * m)
		cy[0] = y - (ly + 1) / 2;
	else if (abs(2 * y - ly) < abs(2 * y - (2 * m - ly)))
		cy[0] = 0;
	else
		cy[0] = m - ly;

	cx[1] = cx[0] + lx;
	cy[1] = cy[0] + ly;

	cout << cx[0] << ' ' << cy[0] << ' ' << cx[1] << ' ' << cy[1];

	return 0;
}