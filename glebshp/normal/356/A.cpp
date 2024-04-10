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

bool used[size];
int par[size];
int n, m;
int ans[size];

int getpar(int p) {
	if (p != par[p]) {
		par[p] = getpar(par[p]);
	}
	return par[p];
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		par[i] = i;

	int lb, rb, win;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &lb, &rb, &win);
		lb--, rb--, win--;

		vector <int> nums;
		int ptr = lb;
		while (ptr <= rb) {
			if (par[ptr] == ptr) {
				nums.pb(ptr);
				ptr++;
			} else {
				ptr = getpar(par[ptr]);
			}
		}

		for (int i = 0; i < (int) nums.size(); i++)
			if (nums[i] != win) {
				ans[nums[i]] = win + 1;
				par[nums[i]] = nums[i] + 1;
			}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);

	return 0;
}