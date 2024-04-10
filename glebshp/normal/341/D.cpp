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
#define taskname "problem_d"

const double pi = acos(-1.0);
const int size = 1010;

long long field[4][size][size];
int n, m;
long long all[4];

inline long long get(int f, int x, int y) {
	long long res = 0;
	for (int xc = x; xc >= 0; xc = (xc & (xc + 1)) - 1)
		for (int yc = y; yc >= 0; yc = (yc & (yc + 1)) - 1)
			res ^= field[f][xc][yc];

	return res;
}

inline long long get(int x, int y) {
	int f = ((x & 1) << 1) + (y & 1);
	return get(f, x, y);
}

inline void change(int f, int x, int y, long long val) {
	for (int xc = x; xc <= n + 1; xc = (xc | (xc + 1)))
		for (int yc = y; yc <= n + 1; yc = (yc | (yc + 1)))
			field[f][xc][yc] ^= val;
	//for (int xc = n - x; xc >= 0; xc = (xc & (xc + 1)) - 1) 
	//	for (int yc = m - y; yc >= 0; yc = (yc & (yc + 1)) - 1)
	//		field[f][xc][yc] ^= val;

}

inline void change(int x, int y, long long val) {
	int f = ((x & 1) << 1) + (y & 1);
	change(f, x, y, val);
	//all[f] ^= val;
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d%d", &n, &m);
	int tp, xc1, xc2, yc1, yc2;
	long long val;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tp);
		if (tp == 1) {
			scanf("%d%d%d%d", &xc1, &yc1, &xc2, &yc2);
			printf("%I64d\n", get(xc2, yc2) ^ get(xc1 - 1, yc2) ^ get(xc2, yc1 - 1) ^ get(xc1 - 1, yc1 - 1));
		} else {
			scanf("%d%d%d%d%I64d", &xc1, &yc1, &xc2, &yc2, &val);
			change(xc1, yc1, val);
			change(xc2 + 1, yc1, val);
			change(xc1, yc2 + 1, val);
			change(xc2 + 1, yc2 + 1, val);
		}
	}

	return 0;
}