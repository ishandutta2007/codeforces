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
#define taskname "problem_c"

const double pi = acos(-1.0);
const int size = 2 * 1000 * 1000;
const int rms = (1 << 21) - 1;
const int hrms = rms / 2;

int n, a, b;
int ans[size];
int mx[size];
int rmq[rms + 1];

int getmin(int i, int j) {
	i += hrms + 1;
	j += hrms + 1;
	int mn = rmq[i];
	while (i < j) {
		if (i & 1) {
			mn = min(mn, rmq[i]);
			i++;
		}
		if (!(j & 1)) {
			mn = min(mn, rmq[j]);
			j--;
		}
		if (i < j) {
			mn = min(mn, min(rmq[i], rmq[j]));
			i /= 2;
			j /= 2;
		}
	}
	if (i <= j) {
		mn = min(mn, min(rmq[i], rmq[j]));
	}

	return mn;
}

void change(int p, int v) {
	p += hrms + 1;
	rmq[p] = v;
	while (p > 1) {
		p /= 2;
		rmq[p] = min(rmq[p * 2], rmq[p * 2 + 1]);
	}
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	vector <int> nums;
	int d;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		nums.pb(d);
	}
	sort(nums.begin(), nums.end());
	nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
	n = nums.size();	
	scanf("%d%d", &a, &b);
	for (int i = 0; i <= a - b; i++)
		mx[i] = 2;
	for (int i = 0; i < n; i++) {
		int v = b / nums[i];
		while (v * nums[i] <= a) {
			if (v * nums[i] >= b)
				mx[v * nums[i] - b] = nums[i];
			v++;
		}
	}

	ans[a - b] = 0;
	for (int i = a - b - 1; i >= 0; i--) {
		ans[i] = a - b - i;
		ans[i] = getmin(i + 1, min(i + mx[i] - 1, a - b)) + 1;
		change(i, ans[i]);
	}

	cout << ans[0] << endl;

	return 0;
}