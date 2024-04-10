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
const long long mdl = 1000 * 1000 * 1000 + 9;

long long k, n, m;

bool check(long long n, long long m, long long k, long long mid) {
	n -= mid * k;
	m -= mid * k;
	
	if (m % (k - 1) == 0)
		return m / (k - 1) <= (n - m + 1);
	else
		return m / (k - 1) <= (n - m);
}

long long pw(long long a, long long b) {
	if (b == 0)
		return 1;
	long long d = pw(a, b / 2);
	d = (d * d) % mdl;
	if (b & 1)
		d = (d * a) % mdl;

	return d;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> n >> m >> k;
	long long lb = 0;
	long long rb = m / k;

	while (rb > lb) {
		long long mid = (lb + rb) / 2;
		if (check(n, m, k, mid))
			rb = mid;
		else
			lb = mid + 1;
	}

	n -= lb * k;
	m -= lb * k;
	long long cur = 0;
	if (lb != 0)
		cur = (k * (pw(2, lb + 1) - 2 + mdl)) % mdl;
	cur = (cur + m) % mdl;

	cout << cur << endl;

	return 0;
}