#include <bits/stdc++.h>
using namespace std;

char s[400010];
int be[400010];
int to[400010];
int L[500010], R[500010];
int ans[500010];
vector <int> from[800010], qry[800010];
int n;

struct SAM {
	int son[800010][27], fa[800010], pos[800010], len[800010], lst, TOT;
	void init() {
		memset(son, 0, sizeof(son)), memset(pos, -1, sizeof(pos));
		memset(fa, 0, sizeof(fa)), memset(len, 0, sizeof(len));
		lst = 1, TOT = 1;
	}
	void append(int x, int id) {
		int p = lst, np = ++TOT; len[np] = len[p] + 1, pos[np] = id, lst = np;
		while (p && !son[p][x]) son[p][x] = np, p = fa[p];
		if (p) {
			int q = son[p][x];
			if (len[q] == len[p] + 1) fa[np] = q;
			else {
				int nq = ++TOT; memcpy(son[nq], son[q], sizeof(son[q])), len[nq] = len[p] + 1;
				fa[nq] = fa[q], fa[q] = fa[np] = nq;
				while (p && son[p][x] == q) son[p][x] = nq, p = fa[p];
			}
		} else fa[np] = 1;
	}
	void BuildT() {
		for (int i = 2; i <= TOT; i++) {
			from[fa[i]].push_back(i);
		}
	}
}sam;

struct Node {
	int sum;
	Node *lson, *rson;
	Node() {sum = 0, lson = rson = 0;}
	void pushup() {sum = (lson ? lson->sum : 0) + (rson ? rson->sum : 0);}
}pool[8000000], *CUR = pool;

void Update(Node *&T, int l, int r, int pos) {
	if (!T) T = CUR++;
	if (l == r) {
		T->sum++;
		return ;
	}
	int mid = l + r >> 1;
	if (pos <= mid) Update(T->lson, l, mid, pos);
	else Update(T->rson, mid + 1, r, pos);
	T->pushup(); 
}

int Query(Node *T, int l, int r, int L, int R) {
	if (!T) return 0;
	if (l == L && r == R) return T->sum;
	int mid = l + r >> 1;
	if (R <= mid) return Query(T->lson, l, mid, L, R);
	if (L > mid) return Query(T->rson, mid + 1, r, L, R);
	return Query(T->lson, l, mid, L, mid) + Query(T->rson, mid + 1, r, mid + 1, R);
}

Node *merge(Node *l, Node *r) {
	if (!l || !r) return l ? l : r;
	l->sum += r->sum;
	l->lson = merge(l->lson, r->lson);
	l->rson = merge(l->rson, r->rson);
	return l;
}

Node *dfs(int x) {
	Node *T = NULL;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		T = merge(T, dfs(v));
	}
	if (sam.pos[x] != -1) Update(T, 0, n - 1, upper_bound(be, be + n, sam.pos[x]) - be - 1);
	for (int i = 0; i < qry[x].size(); i++) {
		int id = qry[x][i];
		ans[id] = Query(T, 0, n - 1, L[id], R[id]);
	}
	return T;
}

int main () {
	int q; scanf("%d%d", &n, &q);
	char *cur = s;
	for (int i = 0; i < n; i++) {
		be[i] = cur - s;
		scanf("%s", cur);
		cur += strlen(cur);
		*cur = '{', cur++;
	}
	be[n] = cur - s;
	int len = strlen(s);
	sam.init();
	for (int i = 0; i < len; i++) {
		sam.append(s[i] - 'a', i);
	}
	for (int i = 0; i < n; i++) {
		int now = 1;
		for (int j = be[i]; j + 1 < be[i + 1]; j++) {
			now = sam.son[now][s[j] - 'a'];
		}
		to[i] = now;
	}
	for (int i = 0; i < q; i++) {
		int k; scanf("%d%d%d", &L[i], &R[i], &k);
		L[i]--, R[i]--, k--;
		qry[to[k]].push_back(i);
	}
	sam.BuildT();
	dfs(1);
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}