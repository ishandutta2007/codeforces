#include <bits/stdc++.h>
using namespace std;

struct Tree{
	int maxj, lazy;
}T[140010];

int f[35010];
int a[35010], cnt[35010], last[35010];

void Push_up(int now){
	T[now].maxj = max(T[now << 1].maxj, T[now << 1 | 1].maxj);
}

void Build(int now, int l, int r){
	if (l == r){
		T[now].maxj = f[l - 1], T[now].lazy = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	Build(now << 1, l, mid);
	Build(now << 1 | 1, mid + 1, r);
	T[now].lazy = 0;
	Push_up(now);
	return ;
}

void Push_down(int now){
	if (!T[now].lazy) return ;
	T[now << 1].maxj += T[now].lazy;
	T[now << 1 | 1].maxj += T[now].lazy;
	T[now << 1].lazy += T[now].lazy;
	T[now << 1 | 1].lazy += T[now].lazy;
	T[now].lazy = 0;
}

void Updata(int now, int l, int r, int L, int R, int v){
	if (l == L && r == R){
		T[now].maxj += v, T[now].lazy += v;
		return ;
	}
	Push_down(now);
	int mid = (l + r) >> 1;
	if (R <= mid) Updata(now << 1, l, mid, L, R, v);
	else if (L > mid) Updata(now << 1 | 1, mid + 1, r, L, R, v);
	else {
		Updata(now << 1, l, mid, L, mid, v);
		Updata(now << 1 | 1, mid + 1, r, mid + 1, R, v);
	}
	Push_up(now);
	return ;
}

int Query(int now, int l, int r, int L, int R){
//	cout << now << " " << l << " " << r << " " << L << " " << R << endl;
	if (l == L && r == R) return T[now].maxj;
	Push_down(now);
	int mid = (l + r) >> 1;
	if (R <= mid) return Query(now << 1, l, mid, L, R);
	if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
	int ans = Query(now << 1, l, mid, L, mid);
	return max(ans, Query(now << 1 | 1, mid + 1, r, mid + 1, R));
}

void print(int now, int l, int r, string p){
	printf("%s%d %d %d\n", p.c_str(), l, r, T[now].maxj);
	if (l == r) return ;
	Push_down(now);
	int mid = (l + r) >> 1;
	print(now << 1, l, mid, p);
	print(now << 1 | 1, mid + 1, r, p);
}

int main(){
	int n, K;
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		last[i] = cnt[a[i]] + 1;
		cnt[a[i]] = i;
	}
	for (int i = 1; i <= K; i++){
		Build(1, 1, n);
		for (int j = 1; j <= n; j++){
			Updata(1, 1, n, last[j], j, 1);
			f[j] = Query(1, 1, n, 1, j);
		}
	}
	printf("%d\n", f[n]);
	return 0;
}