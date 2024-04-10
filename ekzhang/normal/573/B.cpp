#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXSEG 262144
#define INF 1<<30

int N;
int towers[MAXN];
int* lst = new int[MAXSEG];
int* rst = new int[MAXSEG];

void update(int* st, int idx, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) {
		hi = N - 1;
	}
	if (idx < lo || idx > hi) {
		return;
	}
	if (lo == hi) {
		st[node] = x;
		return;
	}
	int mid = (lo + hi) / 2;
	update(st, idx, x, lo, mid, 2 * node + 1);
	update(st, idx, x, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}

int query(int* st, int a, int b, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) {
		hi = N - 1;
	}
	if (lo > b || hi < a) {
		return INF;
	}
	if (lo >= a && hi <= b) {
		return st[node];
	}
	int mid = (lo + hi) / 2;
	return min(query(st, a, b, lo, mid, 2 * node + 1),
			query(st, a, b, mid + 1, hi, 2 * node + 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> towers[i];
		update(lst, i, towers[i] - i);
		update(rst, i, towers[i] + i);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int b = min(query(lst, 0, i) + i, query(rst, i, N - 1) - i);
		b = min(b, min(i + 1, N - i));
		ans = max(ans, b);
	}
	
	cout << ans << endl;
	return 0;
}