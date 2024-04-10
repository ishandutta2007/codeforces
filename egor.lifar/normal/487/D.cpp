#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;


const int MaxM = 10;
const int MaxN = int(1e5) + 100;


struct tans {
	int l, r;
	pair<int, int> go[MaxM];
};


int maxv, m, cur;
bool first;
tans rmq[4 * MaxN];
tans tmp[2];
char a[MaxN][MaxM + 5];
int n, q;


inline void merge(tans &a, tans &b, tans &c) {
	c.l = a.l;
	c.r = b.r;
	for (int i = 0; i < m; i++) {
		if (b.go[i].second < 0 || b.go[i].second >= m) {
			c.go[i] = b.go[i];
			continue;
		}
		c.go[i] = a.go[b.go[i].second];
	}
}


inline void calc(int v) {
	merge(rmq[v * 2], rmq[v * 2 + 1], rmq[v]);
}


inline void init(int pos) {
	rmq[pos + maxv].l = rmq[pos + maxv].r = pos;
	for (int i = 0; i < m; i++) {
		if (a[pos][i] == '^') {
			rmq[pos + maxv].go[i] = make_pair(pos, i);
			continue;
		}
		int cur = i;
		while (cur >= 0 && cur < m && a[pos][cur] == a[pos][i]) {
			if (a[pos][cur] == '>') {
				cur++;
			} else {
				cur--;
			}
		}
		if (cur < 0) {
			rmq[pos + maxv].go[i] = make_pair(pos, -1);
			continue;
		}
		if (cur >= m) {
			rmq[pos + maxv].go[i] = make_pair(pos, m);
			continue;
		}
		if (a[pos][cur] == '^') {
			rmq[pos + maxv].go[i] = make_pair(pos, cur);
			continue;
		}
		rmq[pos + maxv].go[i] = make_pair(-2, -2);
	}
}


inline void recalc(int pos) {
	init(pos);
	pos += maxv;
	while (pos > 1) {
		pos /= 2;
		calc(pos);
	}
}


void get(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		return;
	}
	if (vl >= l && vr <= r) {
		if (first) {
			tmp[cur].l = rmq[v].l;
			tmp[cur].r = rmq[v].r;
			for (int i = 0; i < m; i++) {
				tmp[cur].go[i] = rmq[v].go[i];
			}
			first = false;
		} else {
			merge(rmq[v], tmp[cur], tmp[1 - cur]);
			cur = 1 - cur;
		}
		return;
	}
	int mid = (vl + vr) / 2;
	get(v * 2 + 1, mid + 1, vr, l, r);
	get(v * 2, vl, mid, l, r);
}


inline pair<int, int> calc(int x, int y) {
	first = true;
	cur = 0;
	get(1, 0, maxv - 1, 0, x);
	pair<int, int> ans = tmp[cur].go[y];
	if (ans.first == 0 && ans.second >= 0 && ans.second < m && a[ans.first][ans.second] == '^') {
		ans.first--;
	}
	return ans;
}


inline char get(int c) {
	if (c == 0) {
		return '^';
	}
	if (c == 1) {
		return '<';
	}
	return '>';
}


int main() {
	scanf("%d %d %d", &n, &m, &q);
	gets(a[0]);
	for (int i = 0; i < n; i++) {
		gets(a[i]);
	}
	maxv = 1;
	while (maxv < n) {
		maxv *= 2;
	}
	for (int i = 0; i < n; i++) {
		init(i);
	}
	for (int i = n; i < maxv; i++) {
		for (int j = 0; j < m; j++) {
			rmq[i + maxv].go[j] = make_pair(-2, -2);
		}
	}
	for (int i = maxv - 1; i > 0; i--) {
		calc(i);
	}
	for (int i = 0; i < q; i++) {
		char ch;
		scanf(" %c", &ch);
		if (ch == 'C') {
			int x, y;
			scanf("%d %d %c", &x, &y, &ch);
			x--;y--;
			a[x][y] = ch;
			recalc(x);
			continue;
		}
		int x, y;
		scanf("%d %d", &x, &y);
		x--;y--;
		pair<int, int> ans = calc(x, y);
		printf("%d %d\n", ans.first + 1, ans.second + 1);
	}
	return 0;
}