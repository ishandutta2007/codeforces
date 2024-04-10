#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 100000;

struct Line {
	long long k, b;
	Line() {k = b = 0;}
	Line(long long _k, long long _b) {k = _k, b = _b;}
	long long get(const int &x) const {return x * k + b;}
	long double get(const Line &T) const {return (long double)(T.b - b) / (k - T.k);}
	bool par(const Line &T) const {return k == T.k;}
};

struct Node {
	Line L;
	Node *lson, *rson;
	Node() {L = Line(0, INF), lson = rson = NULL;}
};

void Update(Node *&T, int l, int r, Line tmp) {
	if (!T) {
		T = new Node(), T->L = tmp;
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

Node *merge(Node *L, Node *R, int l, int r) {
	if (!L || !R) return L ? L : R;
	Update(L, l, r, R->L);
	int mid = l + r >> 1;
	L->lson = merge(L->lson, R->lson, l, mid);
	L->rson = merge(L->rson, R->rson, mid + 1, r);
	return L;
}

vector <int> from[100010];
long long dp[100010];
int a[100010], b[100010];

Node *dfs(int x, int last) {
	Node *T = NULL;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		T = merge(T, dfs(v, x), -N, N);
	}
	if (T == NULL) dp[x] = 0;
	else dp[x] = Query(T, -N, N, a[x]);
	Update(T, -N, N, Line(b[x], dp[x]));
	return T;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) {
		printf("%I64d ", dp[i]);
	}
	printf("\n");
	return 0;
}