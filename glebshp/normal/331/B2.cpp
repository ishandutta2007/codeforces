#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 500 * 1000;
const int rms = (1 << 20) - 1;
const int hrms = rms / 2;

int n;
int a[size];
int p[size];
int rmq[rms + 1];

void change(int ps) {
	rmq[ps + hrms + 1] = (p[ps] < p[ps - 1]);
	ps += hrms + 1;
	while (ps > 1) {
		ps /= 2;
		rmq[ps] = rmq[ps * 2] + rmq[ps * 2 + 1];
	}
}

int rss(int v, int lb, int rb, int i, int j) {
	if (lb >= i && rb <= j)
		return rmq[v];
	if (lb > j || rb < i)
		return 0;
	return rss(v * 2, lb, (lb + rb) / 2, i, j) + rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		p[a[i] - 1] = i;
	}
	for (int i = 1; i < n; i++)
		change(i);
	int m, x, y, tp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &tp, &x, &y);
		if (tp == 1)
			printf("%d\n", rss(1, 1, hrms + 1, x + 1, y) + 1);
		else {
			x--, y--;
			swap(a[x], a[y]);
			p[a[x] - 1] = x;
			p[a[y] - 1] = y;
			if (a[x] - 1 > 0)
				change(a[x] - 1);
			if (a[x] < n)
				change(a[x]);
			if (a[y] - 1 > 0)
				change(a[y] - 1);
			if (a[y] < n)
				change(a[y]);
		}
	}

    return 0;
}