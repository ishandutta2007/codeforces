#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

struct Node{
	pii minj;
	int left, right;
}T[25000000];

int tot = 1;

int pushup(int now){
	if (T[now].left == 0) return now;
	T[now].minj = min(T[T[now].left].minj, T[T[now].right].minj);
	return now;
}

int newnode(pii x, int l = 0, int r = 0){
	T[tot].minj = x, T[tot].left = l, T[tot].right = r;
	return pushup(tot++);
}

int newnode(Node x){
	T[tot++] = x;
	return tot - 1;
}

int Build(int l, int r){
	if (l == r) return newnode(mp(INF, -1));
	int mid = l + r >> 1;
	return newnode(mp(INF, -1), Build(l, mid), Build(mid + 1, r));
}

int Update(int now, int l, int r, int pos, pii x){
	if (l == r) return newnode(x);
	int mid = l + r >> 1;
	int res = newnode(T[now]);
	if (pos <= mid) T[res].left = Update(T[now].left, l, mid, pos, x);
	else T[res].right = Update(T[now].right, mid + 1, r, pos, x);
	return pushup(res);
}

pii Query(int now, int l, int r, int L, int R){
	if (l == L && r == R) return T[now].minj;
	int mid = l + r >> 1;
	if (R <= mid) return Query(T[now].left, l, mid, L, R);
	if (L > mid) return Query(T[now].right, mid + 1, r, L, R);
	return min(Query(T[now].left, l, mid, L, mid), Query(T[now].right, mid + 1, r, mid + 1, R));
}

int a[500010], last[500010], Root[500010];

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int now = Build(1, n);
	for (int i = 1; i <= n; i++){
		int x = a[i];
		if (last[x]) now = Update(now, 1, n, last[x], mp(INF, -1));
		now = Update(now, 1, n, i, mp(last[x], a[i])), last[x] = i;
		Root[i] = now;
	}
	int m; scanf("%d", &m);
	while (m--){
		int l, r; scanf("%d%d", &l, &r);
		pii t = Query(Root[r], 1, n, l, r);
		if (t.fi < l) printf("%d\n", t.se);
		else printf("0\n");
	}
	return 0;
}