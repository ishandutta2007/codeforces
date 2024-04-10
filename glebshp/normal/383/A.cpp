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

int n;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);

	long long ans = 0;
	int cnt = 0;
	int d;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		if (d == 0)
			ans += cnt;
		cnt += d;
	}

	cout << ans << endl;

	return 0;
}