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
#define taskname "problem_b"

const double pi = acos(-1.0);
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;
const int size = 200 * 1000;

int rmq[rms + 1];
int n;
int a[size];
int ans[size];

void change(int ps, int val) {
	ps += hrms;
	rmq[ps] = val;
	while (ps > 1) {
		ps /= 2;
		rmq[ps] = max(rmq[ps * 2], rmq[ps * 2 + 1]);
	}
}

int rss(int v, int i, int j, int lb, int rb) {
	if (rb < i || lb > j)
		return 0;
	if (lb >= i && rb <= j)
		return rmq[v];
	return max(rss(v * 2, i, j, lb, (lb + rb) / 2), rss(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb));
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		ans[i] = rss(1, 1, a[i], 1, hrms + 1) + 1;
		change(a[i], ans[i]);
	}

	cout << rss(1, 1, n, 1, hrms + 1) << endl;

	return 0;
}