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

int main() {
	int n;

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> n;
	int sum = 0;
	int cnt = 0;
	double val;
	for (int i = 0; i < 2 * n; i++) {
		cin >> val;
		int v = floor(val * 1000.0 + 1e-1);
		sum += v % 1000;
		if (v % 1000 == 0)
			cnt++;
	}

	for (int i = 0; i < n; i++)
		sum -= 1000;
	for (int i = 0; i < cnt; i++) {
		if (abs(sum + 1000) < abs(sum))
			sum += 1000;
	}

	printf("%.3lf\n", abs(sum) / 1000.0);

	return 0;
}