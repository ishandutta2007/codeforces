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

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n - k - 1; i++) {
		printf("%d ", i);
	}
	int p1 = n - k;
	int p2 = n;
	for (int i = 0; i <= k; i++) {
		if (i % 2 == 0) {
			printf("%d ", p1);
			p1++;
		} else {
			printf("%d ", p2);
			p2--;
		}
	}

	return 0;
}