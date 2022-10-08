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
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int size = 200 * 1000 + 100;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;
const int inf = 1000 * 1000 * 1000;

int rmq[rms + 1];

int rss(int v, int i, int j, int lb, int rb) {
	if (lb > j || rb < i)
		return -inf;
	if (lb >= i && rb <= j)
		return rmq[v];
	return max(rss(v * 2, i, j, lb, (lb + rb) / 2), rss(v * 2 + 1, i, j, (lb + rb) / 2 + 1, rb));
}

void change(int ps, int val) {
	ps += hrms + 1;
	rmq[ps] = val;
	while (ps > 1) {
		ps /= 2;
		rmq[ps] = max(rmq[ps * 2], rmq[ps * 2 + 1]);
	}
}

int val[size];
int from[size];

int main() {
	int n;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i]);
	for (int i = 0; i < n; i++) {
		from[i] = rss(1, val[i], n, 1, hrms + 1);
		change(val[i] - 1, i + 1);
		from[i]--;
	}
	for (int i = 0; i <= rms; i++)
		rmq[i] = 0;
	int glans = 0;
	for (int i = 0; i < n; i++)
		if (from[i] != -1) {
			int d = rss(1, from[i] + 2, i + 1, 1, hrms + 1) + 1;
			glans = max(glans, d);
			change(i, d);
		}
	cout << glans << endl;

	return 0;
}