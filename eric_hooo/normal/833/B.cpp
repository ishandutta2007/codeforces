#include <bits/stdc++.h>
using namespace std;

int a[35010];
int dp[35010];

struct Segment_Tree{
	struct Node{
		int maxj, lazy;
	}T[140010];
	void pushup(int now){
		T[now].maxj = max(T[now << 1].maxj, T[now << 1 | 1].maxj);
	}
	void pushdown(int now){
		if (!T[now].lazy) return ;
		int v = T[now].lazy; T[now].lazy = 0;
		T[now << 1].lazy += v, T[now << 1].maxj += v;
		T[now << 1 | 1].lazy += v, T[now << 1 | 1].maxj += v;
	}
	void Build(int now, int l, int r){
		T[now].maxj = T[now].lazy = 0;
		if (l == r){
			T[now].maxj = dp[l - 1];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int val){
		if (l == L && r == R){
			T[now].maxj += val, T[now].lazy += val;
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
		if (l == L && r == R) return T[now].maxj;
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, l, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

int last[35010];

int main(){
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]); 
	}
	for (int i = 0; i < k; i++){
		seg.Build(1, 1, n);
		memset(last, 0, sizeof(last));
		for (int j = 1; j <= n; j++){
			seg.Update(1, 1, n, last[a[j]] + 1, j, 1);
			last[a[j]] = j;
			dp[j] = seg.Query(1, 1, n, 1, j);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}