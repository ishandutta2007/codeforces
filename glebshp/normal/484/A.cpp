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
#define taskname "task_a"

const double pi = acos(-1.0);
int n;

int popcount(long long x) {
	int c = 0;
	while (x > 0) {
		c += x & 1;
		x /= 2;
	}

	return c;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long lb, rb;
		scanf("%I64d%I64d", &lb, &rb);

		int ans = 0;
		long long ansval = 0;
		int h = 0;
		while (true) {
			int nv = popcount(lb) + h;
			long long nav = (lb << h) + (1ll << h) - 1;
			if (nv > ans || (nv == ans && nav < ansval)) {
				ans = nv;
				ansval = nav;
			}
			nv = popcount(rb) + h;
			nav = (rb << h) + (1ll << h) - 1;
			if (nv > ans || (nv == ans && nav < ansval)) {
				ans = nv;
				ansval = nav;
			}
			
			if (lb % 2 == 0)
				lb++;
			if (rb > 0 && rb % 2 == 0)
				rb--;
			if (lb > rb)
				break;
			h++;
			lb /= 2;
			rb /= 2;
		}

		printf("%I64d\n", ansval);
	}

	return 0;
}