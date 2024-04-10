#include <bits/stdc++.h>
using namespace std;

int a[200010];
int n;

struct Segment_tree{
	struct Node{
		int sum, deep;
	}T[800010];
	void pushup(int now){
		if (T[now].deep & 1) T[now].sum = T[now << 1].sum | T[now << 1 | 1].sum;
		else T[now].sum = T[now << 1].sum ^ T[now << 1 | 1].sum;
	}
	void Build(int now, int l, int r, int d){
		T[now].deep = d;
		if (l == r){
			T[now].sum = a[l];
			return ; 
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid, d - 1), Build(now << 1 | 1, mid + 1, r, d - 1);
		pushup(now);
	}
	void Update(int now, int l, int r, int pos, int x){
		if (l == r){
			T[now].sum = x;
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
		pushup(now);
	}
	int Query(){return T[1].sum;}
}seg;

int main(){
	int m, k;
	scanf("%d%d", &n, &m);
	k = n, n = 1 << n;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	seg.Build(1, 1, n, k);
	while (m--){
		int pos, x; scanf("%d%d", &pos, &x);
		seg.Update(1, 1, n, pos, x);
		printf("%d\n", seg.Query());
	}
	return 0;
}