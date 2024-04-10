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

const int size = 95542721;
const long long mdl = size;
const int rms = (1 << 18) - 1;
const int hrms = rms / 2;
const int nsize = 200 * 1000;

long long rmq[rms + 1][48];
int shift[rms + 1];
int num[nsize];
int n;

inline long long nx(long long v) {
	return ((v * v) % mdl * v) % mdl;
}

long long getsum(int v, int lb, int rb, int i, int j) {
	if (lb >= i && rb <= j)
		return rmq[v][shift[v]];
	if (lb > j || rb < i)
		return 0;
	shift[v * 2] = (shift[v * 2] + shift[v]) % 48;
	shift[v * 2 + 1] = (shift[v * 2 + 1] + shift[v]) % 48;
	shift[v] = 0;
	for (int i = 0; i < 48; i++) {
		rmq[v][i] = rmq[v * 2][(shift[v * 2] + i) % 48] + rmq[v * 2 + 1][(shift[v * 2 + 1] + i) % 48];
		if (rmq[v][i] >= mdl)
			rmq[v][i] -= mdl;
	}
	long long res = getsum(v * 2, lb, lb + (rb - lb) / 2, i, j) + getsum(v * 2 + 1, lb + (rb - lb) / 2 + 1, rb, i, j);
	if (res >= mdl)
		res -= mdl;
	return res;
}

void change(int v, int lb, int rb, int i, int j) {
	if (lb >= i && rb <= j) {
		shift[v]++;
		return;
	}
	if (lb > j || rb < i)
		return;
	shift[v * 2] = (shift[v * 2] + shift[v]) % 48;
	shift[v * 2 + 1] = (shift[v * 2 + 1] + shift[v]) % 48;
	change(v * 2, lb, lb + (rb - lb) / 2, i, j);
	change(v * 2 + 1, lb + (rb - lb) / 2 + 1, rb, i, j);
	shift[v] = 0;
	for (int i = 0; i < 48; i++) {
		rmq[v][i] = rmq[v * 2][(shift[v * 2] + i) % 48] + rmq[v * 2 + 1][(shift[v * 2 + 1] + i) % 48];
		if (rmq[v][i] >= mdl)
			rmq[v][i] -= mdl;
	}
}

int main() {
	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		num[i] %= mdl;
		rmq[i + hrms + 1][0] = num[i];
		for (int j = 1; j < 48; j++)
			rmq[i + hrms + 1][j] = nx(rmq[i + hrms + 1][j - 1]);
	}
	for (int i = hrms; i > 0; i--) {
		for (int j = 0; j < 48; j++) {
			rmq[i][j] = rmq[i * 2][j] + rmq[i * 2 + 1][j];
			if (rmq[i][j] >= mdl)
				rmq[i][j] -= mdl;
		}
	}

	int m;
	scanf("%d", &m);
	int tp, lb, rb;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &tp, &lb, &rb);
		//lb--, rb--;
		if (tp == 1) {
			printf("%d\n", int(getsum(1, 1, hrms + 1, lb, rb)));
		} else {
			change(1, 1, hrms + 1, lb, rb);
		}
	}

	return 0;
}