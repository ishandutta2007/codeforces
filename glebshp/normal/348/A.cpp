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
const long long inf = (long long) 1e18;
const int size = 200 * 1000;

long long num[size];
int n;

bool check(long long rds) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum = min(inf, sum + rds - num[i]);
	}

	return sum >= rds;
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &num[i]);

	long long lb = 0;
	long long rb = inf;

	for (int i = 0; i < n; i++)
		lb = max(lb, num[i]);

	while (lb < rb) {
		long long mid = (lb + rb) / 2;
		if (check(mid))
			rb = mid;
		else
			lb = mid + 1;
	}

	cout << lb << endl;

	return 0;
}