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

long long nod(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

int n;

long long a[size];

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	sort(a, a + n);

	long long sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		sum2 += a[i] * i - sum1;
		sum1 += a[i];
	}
	//cout << sum1 << ' ' << sum2 << endl;

	long long a = sum1 + sum2 * 2;
	long long b = n;
	long long d = nod(a, b);
	cout << a / d << ' ' << b / d << endl;

	return 0;
}