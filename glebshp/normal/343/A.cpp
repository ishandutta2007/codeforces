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

long long a, b;

long long nod(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

long long getans(long long a, long long b) {
	long long d = nod(a, b);
	a /= d;
	b /= d;

	if (a == 1)
		return b;
	if (b == 1)
		return a;
	if (a > b)
		return getans(a % b, b) + a / b;
	return getans(a, b % a) + b / a;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> a >> b;
	cout << getans(a, b) << endl;

	return 0;
}