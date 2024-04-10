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
const int size = 1010;
const int px[] = {1, 0, -1, 0};
const int py[] = {0, 1, 0, -1};
const int mdeg = 12;
const int onelvl = 20;

int ways[size][size];
int n, b;
int ans[mdeg][size * size * 4];

inline int dirts(int x, int y, int d) {
	return d * (b + 1) * (b + 1) + x * (b + 1) + y;
}

inline void backts(int num, int &x, int &y, int &d) {
	y = num % (b + 1);
	num /= b + 1;
	x = num % (b + 1);
	num /= b + 1;
	d = num;
}

int main() {
//    freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &b);
	for (int i = 0; i <= b; i++)
		for (int j = 0; j <= b; j++)
			ways[i][j] = -1;
	int xs1, xs2, ys1, ys2;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &xs1, &ys1, &xs2, &ys2);
		int len = abs(xs1 - xs2) + abs(ys1 - ys2);
		int dir = -1;
		for (int j = 0; j < 4; j++)
			if (xs1 + px[j] * len == xs2 && ys1 + py[j] * len == ys2)
				dir = j;
		for (int j = 0; j <= len; j++)
			ways[xs1 + px[dir] * j][ys1 + py[dir] * j] = dir;
	}
	int hx, hy, hd;
	for (int i = 0; i <= b; i++)
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k < 4; k++) {
				if (ways[i][j] == -1) {
					hx = i + px[k];
					hy = j + py[k];
					hx = max(0, min(hx, b));
					hy = max(0, min(hy, b));
					ans[0][dirts(i, j, k)] = dirts(hx, hy, k);
				} else {
					hd = ways[i][j];
					hx = i + px[hd];
					hy = j + py[hd];
					hx = max(0, min(hx, b));
					hy = max(0, min(hy, b));
					ans[0][dirts(i, j, k)] = dirts(hx, hy, hd);
			//		cout << 0 << ' ' << dirts(i, j, k) << ' ' << ans[0][dirts(i, j, k)] << endl;
				}
			}
		}
	for (int lvl = 1; lvl < mdeg; lvl++) {
		for (int i = 0; i <= b; i++)
			for (int j = 0; j <= b; j++)
				for (int k = 0; k < 4; k++) {
					int num = dirts(i, j, k);
					for (int hp = 0; hp < onelvl; hp++)
						num = ans[lvl - 1][num];
					ans[lvl][dirts(i, j, k)] = num;
				}
	}

	int q, xc, yc;
	char mdir;
	long long len;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d %c%I64d", &xc, &yc, &mdir, &len);
		int d = -1;
		if (mdir == 'R')
			d = 0;
		if (mdir == 'U')
			d = 1;
		if (mdir == 'L')
			d = 2;
		if (mdir == 'D')
			d = 3;
		int num = dirts(xc, yc, d);
		for (int j = 0; j < mdeg; j++) {
			while (len % onelvl != 0) {
		//		cout << "move " << num << " ";
				num = ans[j][num];
		//		cout << num << endl;
				len--;
			}
			len /= onelvl;
		}

		int xa, ya, da;
		backts(num, xa, ya, da);
		printf("%d %d\n", xa, ya);
	}

    return 0;
}