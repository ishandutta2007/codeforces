#include <bits/stdc++.h>
using namespace std;

vector <int> from[200010];
int size[200010], id[200010], num[200010], a[200010];
int cnt;

void dfs(int x){
	size[x] = 1, id[x] = ++cnt, num[cnt] = x;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		dfs(v), size[x] += size[v];
	}
}

struct Segment_Tree{
	struct Node{
		int sum[2];
		int lazy;
	}T[800010];
	void pushup(int now){
		T[now].sum[0] = T[now << 1].sum[0] + T[now << 1 | 1].sum[0];
		T[now].sum[1] = T[now << 1].sum[1] + T[now << 1 | 1].sum[1];
	}
	void pushdown(int now){
		if (!T[now].lazy) return ;
		T[now].lazy = 0;
		swap(T[now << 1].sum[0], T[now << 1].sum[1]), T[now << 1].lazy ^= 1;
		swap(T[now << 1 | 1].sum[0], T[now << 1 | 1].sum[1]), T[now << 1 | 1].lazy ^= 1;
	}
	void Build(int now, int l, int r){
		T[now].sum[0] = T[now].sum[1] = T[now].lazy = 0;
		if (l == r){
			T[now].sum[a[num[l]]]++;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R){
		if (l == L && r == R){
			swap(T[now].sum[0], T[now].sum[1]);
			T[now].lazy ^= 1;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R);
		else Update(now << 1, l, mid, L, mid), Update(now << 1 | 1, mid + 1, r, mid + 1, R);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R){
		if (l == L && r == R) return T[now].sum[1];
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
}seg;

int main(){
	int n; scanf("%d", &n);
	for (int i = 2; i <= n; i++){
		int p; scanf("%d", &p);
		from[p].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	int q; scanf("%d", &q);
	seg.Build(1, 1, n);
	while (q--){
		char op[10]; int x;
		scanf("%s%d", op, &x);
		if (op[0] == 'g') printf("%d\n", seg.Query(1, 1, n, id[x], id[x] + size[x] - 1));
		else seg.Update(1, 1, n, id[x], id[x] + size[x] - 1);
	}
	return 0;
}