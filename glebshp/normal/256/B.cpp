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

long long n, x, y, c;

long long getloc(long long a, long long b, long long d) {
	if (a > b)
		swap(a, b);

	if (a >= d && b >= d)
		return d * (d + 1) / 2;

	if (a < d  && b >= d)
		return (d - a) * a + a * (a + 1) / 2;

	if (d >= (a + b - 1))
		return a * b;

	d = (a + b - 1 - d);
	return a * b - d * (d + 1) / 2;
}

long long get(long long d) {
	return getloc(x - 1, y - 1, max(0ll, d - 1)) + getloc(n - x, n - y, max(0ll, d - 1)) + getloc(x - 1, n - y, max(0ll, d - 1)) + getloc(n - x, y - 1, max(0ll, d - 1)) 
		   + min(x - 1, d) + min(y - 1, d) + min(n - x, d) + min(n - y, d) + 1;
}

int main() {
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> x >> y >> c;

	long long lb = 0;
	long long rb = 2 * n;
	while (lb < rb) {
		long long mid = (lb + rb) / 2;
		if (get(mid) < c)
			lb = mid + 1;
		else
			rb = mid;
	}

	cout << lb << endl;

	return 0;
}