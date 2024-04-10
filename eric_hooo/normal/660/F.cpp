#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long N = 2000000000000;

int a[200010];
long long S[200010], SS[200010];

struct Line {
	long long k, b;
	Line() {k = b = 0;}
	Line(long long _k, long long _b) {k = _k, b = _b;}
	long long get(const long long &x) const {return x * k + b;}
};

struct Node {
	Line L;
	Node *lson, *rson;
	Node(Line _L = Line(0, INF)) {L = _L, lson = rson = NULL;}
}*T = NULL;

void Update(Node *&T, long long l, long long r, Line tmp) {
	if (!T) {
		T = new Node(tmp);
		return ;
	}
	long long mid = l + r >> 1;
	if (T->L.get(mid) < tmp.get(mid)) swap(T->L, tmp);
	if (l == r) return ;
	if (tmp.k < T->L.k) Update(T->lson, l, mid, tmp);
	else if (tmp.k > T->L.k) Update(T->rson, mid + 1, r, tmp);
}

long long Query(Node *T, long long l, long long r, long long pos) {
	if (!T) return -INF;
	long long val = T->L.get(pos);
	if (l == r) return val;
	long long mid = l + r >> 1;
	if (pos <= mid) return max(Query(T->lson, l, mid, pos), val);
	return max(Query(T->rson, mid + 1, r, pos), val);
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		S[i] = S[i - 1] + a[i];
		SS[i] = SS[i - 1] + S[i];
	}
	long long ans = 0;
	T = NULL;
	for (int i = n; i >= 1; i--) {
		Update(T, -N, N, Line(-i, SS[i]));
		ans = max(ans, Query(T, -N, N, S[i - 1]) + (i - 1) * S[i - 1] - SS[i - 1]);
	}
	printf("%I64d\n", ans);
	return 0;
}