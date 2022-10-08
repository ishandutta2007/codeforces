#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

long long nod(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

int main() {
	long long n, m, x, y, a, b;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> m >> x >> y >> a >> b;

	long long d = nod(a, b);
	a /= d;
	b /= d;

	d = min(n / a, m / b);
	long long sx = a * d;
	long long sy = b * d;
	long long bx = x - sx / 2 - sx % 2;
	long long by = y - sy / 2 - sy % 2;
	if (bx < 0)
		bx = 0;
	if (by < 0)
		by = 0;
	if (bx + sx > n)
		bx = n - sx;
	if (by + sy > m)
		by = m - sy;
	
	cout << bx << ' ' << by << ' ' << bx + sx << ' ' << by + sy << endl;

	return 0;
}