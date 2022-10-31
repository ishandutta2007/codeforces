#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
#define MAX 805050
int l[MAX], r[MAX];
int tree[MAX], maxv[MAX], minv[MAX];
int s;
void init(int x = 1) {
	if (x >= s) {
		l[x] = r[x] = x - s + 1;
		maxv[x] = max(tree[x], 0);
		minv[x] = min(tree[x], 0);
		return;
	}
	init(x * 2);
	init(x * 2 + 1);
	l[x] = l[x * 2];
	r[x] = r[x * 2 + 1];
	maxv[x] = max(tree[x * 2] + maxv[x * 2 + 1], maxv[x * 2]);
	minv[x] = min(tree[x * 2] + minv[x * 2 + 1], minv[x * 2]);
	tree[x] = tree[x * 2] + tree[x * 2 + 1];
}
int sumquery(int low, int high, int loc = 1) {
	if (high < low) return 0;
	if (loc >= 2 * s) return 0;
	if (l[loc] == low && r[loc] == high) return tree[loc];
	if (r[loc * 2] >= high) return sumquery(low, high, loc * 2);
	if (l[loc * 2 + 1] <= low) return sumquery(low, high, loc * 2 + 1);
	return sumquery(low, r[loc * 2], loc * 2) + sumquery(l[loc * 2 + 1], high, loc * 2 + 1);
}
pp query(int low, int high, int loc = 1) {
	if (high < low) return { 0, 0 };
	if (loc >= 2 * s) return { 0, 0 };
	if (l[loc] == low && r[loc] == high) return { maxv[loc], minv[loc] };
	if (r[loc * 2] >= high) return query(low, high, loc * 2);
	if (l[loc * 2 + 1] <= low) return query(low, high, loc * 2 + 1);
	pp p1, p2;
	p1 = query(low, r[loc * 2], loc * 2);
	p2 = query(l[loc * 2 + 1], high, loc * 2 + 1);
	int sum = sumquery(low, r[loc * 2], loc * 2);
	return { max(p1.first, p2.first + sum), min(p1.second, p2.second + sum) };
}
int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, M;
		cin >> N >> M;
		s = 1 << (int)ceil(log2(N));
		int i;
		char str[MAX];
		cin >> str;
		for (i = 0; i <= 2 * s; i++) l[i] = r[i] = tree[i] = minv[i] = maxv[i] = 0;
		for (i = 0; i < N; i++) {
			if (str[i] == '-') tree[i + s] = -1;
			else tree[i + s] = 1;
		}
		init();
		int l, r;
		for (i = 1; i <= M; i++) {
			cin >> l >> r;
			if (l == 1 && r == N) cout << 1 << endl;
			else if (l == 1) {
				pp res = query(r + 1, N);
				cout << res.first - res.second + 1 << endl;
			}
			else if (r == N) {
				pp res;
				res = query(1, l - 1);
				cout << res.first - res.second + 1 << endl;
			}
			else {
				pp res1 = query(1, l - 1);
				pp res2 = query(r + 1, N);
				int sum = sumquery(1, l - 1);
				res2.first += sum;
				res2.second += sum;
				cout << max(res1.first, res2.first) - min(res1.second, res2.second) + 1 << endl;
			}
		}
	}
}