#include <bits/stdc++.h>
using namespace std;

struct Segment_tree{
	struct Node{
		int sum, lazy;
	}T[400010];
	void pushup(int now){
		T[now].sum = T[now << 1].sum & T[now << 1 | 1].sum;
	}
	void pushdown(int now){
		if (!T[now].lazy) return ;
		int v = T[now].lazy; T[now].lazy = 0;
		T[now << 1].sum |= v, T[now << 1].lazy |= v;
		T[now << 1 | 1].sum |= v, T[now << 1 | 1].lazy |= v;
	}
	void Build(int now, int l, int r){
		T[now].sum = T[now].lazy = 0;
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int L, int R, int val){
		if (l == L && r == R){
			T[now].sum |= val, T[now].lazy |= val;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, val);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, val);
		else Update(now << 1, l, mid, L, mid, val), Update(now << 1 | 1, mid + 1, r, mid + 1, R, val);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R){
		if (l == L && r == R) return T[now].sum;
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) & Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
	void print(int now, int l, int r){
		if (l == r){
			printf("%d ", T[now].sum);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		print(now << 1, l, mid), print(now << 1 | 1, mid + 1, r);
	}
}seg;

int l[100010], r[100010], q[100010];

int main(){
	int n, m; scanf("%d%d", &n, &m);
	seg.Build(1, 1, n);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &l[i], &r[i], &q[i]);
		seg.Update(1, 1, n, l[i], r[i], q[i]);
	}
	for (int i = 0; i < m; i++){
		if (seg.Query(1, 1, n, l[i], r[i]) != q[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	seg.print(1, 1, n);
	printf("\n");
	return 0;
}