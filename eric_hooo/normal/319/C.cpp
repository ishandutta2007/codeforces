#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1000000000;

int a[100010], b[100010];
long long dp[100010];

struct Line {
	long long k, b;
	Line() {k = b = 0;}
	Line(long long _k, long long _b) {k = _k, b = _b;}
	long long get(const int &x) const {return x * k + b;}
};

struct Node {
	Line L;
	Node *lson, *rson;
	Node(Line _L = Line(0, INF)) {L = _L, lson = rson = NULL;}
}*T = NULL;

void Update(Node *&T, int l, int r, Line tmp) {
	if (!T) {
		T = new Node(tmp);
		return ;
	}
	int mid = l + r >> 1;
	if (T->L.get(mid) > tmp.get(mid)) swap(T->L, tmp);
	if (l == r) return ;
	if (tmp.k > T->L.k) Update(T->lson, l, mid, tmp);
	else Update(T->rson, mid + 1, r, tmp);
}

long long Query(Node *T, int l, int r, int pos) {
	if (!T) return INF;
	long long val = T->L.get(pos);
	if (l == r) return val;
	int mid = l + r >> 1;
	if (pos <= mid) return min(Query(T->lson, l, mid, pos), val);
	return min(Query(T->rson, mid + 1, r, pos), val);
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		Update(T, 0, N, Line(b[i - 1], dp[i - 1]));
		dp[i] = Query(T, 0, N, a[i]);
	}
	printf("%I64d\n", dp[n]);
	return 0;
}