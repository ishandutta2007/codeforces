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
#define taskname "task_b"

const double pi = acos(-1.0);
const int size = 2 * 1000 * 1000 + 10;

bool used[size];
int mxv[size];
int n;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		used[d] = true;
	}

	mxv[0] = 0;
	for (int i = 1; i < size; i++) {
		if (used[i]) {
			mxv[i] = i;
		} else {
			mxv[i] = mxv[i - 1];
		}
	}

	int ans = 0;
	for (int i = 1; i < size; i++)
		if (used[i]) {
			for (int j = 2 * i; j < size; j += i) {
				ans = max(ans, mxv[j - 1] - (j - i));
			}
		}

	printf("%d\n", ans);

	return 0;
}