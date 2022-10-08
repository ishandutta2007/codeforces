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
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;
const int size = 300 * 1000 + 10;

int rmq[rms + 1];
int n, m;
int lb[size], rb[size], q[size];
int val[size];

void change(int v, int lb, int rb, int i, int j, int val) {
	if (lb > j || rb < i)
		return;
	if (lb >= i && rb <= j) {
		rmq[v] |= val;
		return;
	}

	change(v * 2, lb, (lb + rb) / 2, i, j, val);
	change(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j, val);
}

int rss(int v, int lb, int rb, int i, int j) {
	if (lb > j || rb < i) {
		return (1 << 30) - 1;
	}
	if (lb >= i && rb <= j) {
		return rmq[v];
	}

	return rss(v * 2, lb, (lb + rb) / 2, i, j) & rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j);
}

int main() {
	/*
	freopen("input.txt", "w", stdout);
	int n = 100 * 1000;
	cout << n << ' ' << n << endl;
	for (int i = 0; i < n; i++)
		cout << 1 << ' ' << n << " 29434" << endl;
	return 0;
	*/
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &lb[i], &rb[i], &q[i]);
		
		change(1, 1, hrms + 1, lb[i], rb[i], q[i]);
	}

	for (int i = 0; i < n; i++) {
		int p = i + 1 + hrms;
		int v = 0;
		while (p > 0) {
			v |= rmq[p];
			p /= 2;
		}

		val[i] = v;
	}

	for (int i = 0; i <= rms; i++)
		rmq[i] = 0;
	for (int i = 0; i < n; i++) {
		int p = i + 1 + hrms;
		rmq[p] = val[i];
	}
	for (int i = hrms; i > 0; i--) {
		rmq[i] = rmq[i * 2] & rmq[i * 2 + 1];
	}

	bool flag = true;
	for (int i = 0; i < m; i++) {
		if (rss(1, 1, hrms + 1, lb[i], rb[i]) != q[i])
			flag = false;
	}

	if (flag) {
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%d%c", val[i], " \n"[i == n - 1]);
	} else {
		printf("NO\n");
	}

	return 0;
}