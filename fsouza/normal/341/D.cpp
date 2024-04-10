#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 1023

typedef long long lint;

using namespace std;

int n;
lint B[2][2][1+MAXN][1+MAXN];

lint query(int x, int y)
{
	lint ret = 0;

	for (int x2 = x; x2 > 0; x2 -= x2&-x2)
		for (int y2 = y; y2 > 0; y2 -= y2&-y2)
			ret ^= B[x&1][y&1][x2][y2];

	return ret;
}

vector <pair <int, int> > blas[2][2];

void apply(int ox, int oy, int x, int y, lint val)
{
	for (int x2 = x; x2 <= n; x2 += x2&-x2)
		for (int y2 = y; y2 <= n; y2 += y2&-y2)
			B[ox][oy][x2][y2] ^= val;
}

void commit(lint val)
{
	for (int ox = 0; ox < 2; ox++) {
		for (int oy = 0; oy < 2; oy++) {
			sort(blas[ox][oy].begin(), blas[ox][oy].end());

			vector <pair <int, int> >& v = blas[ox][oy];

			int j = 0;
			for (int i = 0; i < (int)v.size(); i = j) {
				while (j < (int)v.size() && v[j] == v[i])
					j++;

				if ((j-i)%2)
					apply(ox, oy, v[i].first, v[i].second, val);
			}

			v.clear();
		}
	}
}

void update2(int ox, int oy, int x, int y, lint val)
{
	blas[ox][oy].push_back(make_pair(x, y));
}

void update2(int ox, int oy, int x0, int x1, int y0, int y1, lint val)
{
	update2(ox, oy, x0, y0, val);
	update2(ox, oy, x1+1, y0, val);
	update2(ox, oy, x0, y1+1, val);
	update2(ox, oy, x1+1, y1+1, val);
}

void update(int x, int y, lint val)
{
	{
		update2(1, 1, 1, x, 1, y, val);
	}
	{
		if (x%2 == 1) {
			update2(0, 1, x+1, n, 1, y, val);
			update2(1, 1, x+1, n, 1, y, val);
		}
	}
	{
		if (y%2 == 1) {
			update2(1, 0, 1, x, y+1, n, val);
			update2(1, 1, 1, x, y+1, n, val);
		}
	}
	{
		if ((x*y%2) == 1) {
			update2(0, 0, x+1, n, y+1, n, val);
			update2(0, 1, x+1, n, y+1, n, val);
			update2(1, 0, x+1, n, y+1, n, val);
			update2(1, 1, x+1, n, y+1, n, val);
		}
	}
}

int main(int argc, char ** argv)
{
	int nop;

	cin >> n >> nop;

	memset(B, 0, sizeof(B));

	for (int op = 0; op < nop; op++) {
		int type;
		int x0, y0, x1, y1;

		cin >> type;
		cin >> x0 >> y0 >> x1 >> y1;

		if (type == 1) {
			cout << (query(x1, y1) ^ query(x0-1, y1) ^ query(x1, y0-1) ^ query(x0-1, y0-1)) << endl;
		} else {
			lint v;
			cin >> v;
			update(x1, y1, v);
			update(x0-1, y1, v);
			update(x1, y0-1, v);
			update(x0-1, y0-1, v);

			commit(v);
		}
	}

	return 0;
}