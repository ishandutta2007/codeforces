#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pll;

const int N = 1000000;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int a[200010];
long long sum[200010];
pll st[200010];

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
	if (T->L.get(mid) < tmp.get(mid)) swap(T->L, tmp);
	if (l == r) return ;
	if (tmp.k < T->L.k) Update(T->lson, l, mid, tmp);
	else Update(T->rson, mid + 1, r, tmp);
}

long long Query(Node *T, int l, int r, int pos) {
	if (!T) return -INF;
	long long val = T->L.get(pos);
	if (l == r) return val;
	int mid = l + r >> 1;
	if (pos <= mid) return max(Query(T->lson, l, mid, pos), val);
	return max(Query(T->rson, mid + 1, r, pos), val);
}

int main () {
	int n; scanf("%d", &n);
	long long tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		tot += 1ll * i * a[i];
	}
	long long ans = 0;
	T = NULL;
	for (int i = n - 1; i >= 1; i--) {
		Update(T, -N, N, Line(i + 1, -sum[i + 1]));
		ans = max(ans, Query(T, -N, N, a[i]) - 1ll * i * a[i] + sum[i]);
	}
	T = NULL;
	for (int i = 2; i <= n; i++) {
		Update(T, -N, N, Line(i - 1, -sum[i - 2]));
		ans = max(ans, Query(T, -N, N, a[i]) - 1ll * i * a[i] + sum[i - 1]);
	}
	printf("%I64d\n", ans + tot);
	return 0;
}