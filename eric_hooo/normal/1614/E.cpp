#include <bits/stdc++.h>
using namespace std;

int n;
int T[200010];
vector <int> qry[200010];

struct Node {
	int sum, minj, maxj;
	Node *lson, *rson;
	void init(int x) {sum = x, lson = rson = NULL;}
	void pushup(int l, int r) {
		int mid = l + r >> 1;
		sum = (lson ? lson->sum : mid - l + 1) + (rson ? rson->sum : r - mid);
		minj = maxj = -1;
		auto Calc = [&](Node *T, int l, int r) -> void {
			int mn = T ? T->minj : l, mx = T ? T->maxj : r;
			if (mn != -1 && (minj == -1 || mn < minj)) minj = mn;
			if (mx != -1 && (maxj == -1 || mx > maxj)) maxj = mx;
		};
		Calc(lson, l, mid), Calc(rson, mid + 1, r);
	}
}POOL[20000010], *CUR = POOL, *rt = NULL;

int Query(Node *T, int l, int r, int L, int R) {
	if (!T) return R - L + 1;
	if (l == L && r == R) return T->sum;
	int mid = l + r >> 1;
	if (R <= mid) return Query(T->lson, l, mid, L, R);
	if (L > mid) return Query(T->rson, mid + 1, r, L, R);
	return Query(T->lson, l, mid, L, mid) + Query(T->rson, mid + 1, r, mid + 1, R);
}

void Update(Node *&T, int l, int r, int x, int v) {
	if (!T) (T = CUR++)->init(r - l + 1);
	if (l == r) {
		T->sum += v, T->minj = T->maxj = -1;
		return ;
	}
	int mid = l + r >> 1;
	if (x <= mid) Update(T->lson, l, mid, x, v);
	else Update(T->rson, mid + 1, r, x, v);
	T->pushup(l, r);
}

int GetNum(Node *T, int l, int r, int k) {
	if (!T) return l + k - 1;
	int mid = l + r >> 1;
	int lsz = (T->lson ? T->lson->sum : mid - l + 1);
	if (lsz >= k) return GetNum(T->lson, l, mid, k);
	return GetNum(T->rson, mid + 1, r, k - lsz);
}

int GetPre(Node *T, int l, int r, int x) {
	if (x < l) return -1;
	if (x > r) return T ? T->maxj : r;
	if (!T) return x == l ? -1 : x - 1;
	if (l == r) return -1;
	int mid = l + r >> 1;
	if (x <= mid) return GetPre(T->lson, l, mid, x);
	int tmp = GetPre(T->rson, mid + 1, r, x);
	return tmp == -1 ? GetPre(T->lson, l, mid, x) : tmp;
}

int GetSuc(Node *T, int l, int r, int x) {
	if (x < l) return T ? T->minj : l;
	if (x > r) return -1;
	if (!T) return x == r ? -1 : x + 1;
	if (l == r) return -1;
	int mid = l + r >> 1;
	if (x > mid) return GetSuc(T->rson, mid + 1, r, x);
	int tmp = GetSuc(T->lson, l, mid, x);
	return tmp == -1 ? GetSuc(T->rson, mid + 1, r, x) : tmp;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &T[i]);
		int k; scanf("%d", &k);
		while (k--) {
			int x; scanf("%d", &x);
			qry[i].push_back(x);
		}
	}
	int lstans = 0;
	int L = 0, R = 1000000000, cl = L, cr = R;
	for (int i = 0; i < n; i++) {
		int x = T[i];
		if (x < cl) cl--, cr--;
		else if (x > cr) cl++, cr++;
		else {
			x = GetNum(rt, L, R, x - cl + 1);
			int pre = GetPre(rt, L, R, x), suc = GetSuc(rt, L, R, x);
			if (pre != -1) Update(rt, L, R, x, -1);
			if (suc != -1) Update(rt, L, R, suc, -1);
			if (pre != -1) cl++;
			if (suc != -1) cr--;
		}
		for (auto x : qry[i]) {
			x = (x + lstans) % 1000000001;
			printf("%d\n", lstans = cl + Query(rt, L, R, L, x) - 1);
		}
	}
	return 0;
}