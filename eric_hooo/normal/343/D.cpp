#include <bits/stdc++.h>
using namespace std;

vector <int> from[500010];
int size[500010], fa[500010], son[500010], top[500010], id[500010], num[500010];
int n, cnt = 1;

void dfs1(int x, int last){
	size[x] = 1, fa[x] = last, son[x] = -1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		dfs1(v, x), size[x] += size[v];
		if (son[x] == -1 || size[son[x]] < size[v]) son[x] = v;
	}
}

void dfs2(int x, int t){
	top[x] = t, id[x] = cnt++, num[id[x]] = x;
	if (son[x] == -1) return ;
	dfs2(son[x], t);
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
}

struct Segment_tree{
	struct Node{
		int val, lazy;
	}T[2000010];
	void pushup(int now){}
	void pushdown(int now){
		if (T[now].lazy == -1) return ;
		int v = T[now].lazy; T[now].lazy = -1;
		T[now << 1].val = T[now << 1].lazy = v;
		T[now << 1 | 1].val = T[now << 1 | 1].lazy = v;
	}
	void Build(int now, int l, int r){
		T[now].lazy = -1;
		if (l == r){
			T[now].val = 0;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int x){
		if (l == L && r == R){
			T[now].val = T[now].lazy = x;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
	}
	int Query(int now, int l, int r, int pos){
		if (l == r) return T[now].val;
		pushdown(now);
		int mid = l + r >> 1;
		if (pos <= mid) return Query(now << 1, l, mid, pos);
		return Query(now << 1 | 1, mid + 1, r, pos);
	}
}seg;

void work1(int x){seg.Update(1, 1, n, id[x], id[x] + size[x] - 1, 1);}

void work2(int x){
	while (top[x] != 1){
		seg.Update(1, 1, n, id[top[x]], id[x], 0);
		x = fa[top[x]];
	}
	seg.Update(1, 1, n, id[top[x]], id[x], 0);
}

int work3(int x){return seg.Query(1, 1, n, id[x]);}

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	dfs1(1, 1), dfs2(1, 1), seg.Build(1, 1, n);
	int m; scanf("%d", &m);
	while (m--){
		int op, x; scanf("%d%d", &op, &x);
		if (op == 1) work1(x);
		else if (op == 2) work2(x);
		else if (op == 3) printf("%d\n", work3(x));
	}
	return 0;
}