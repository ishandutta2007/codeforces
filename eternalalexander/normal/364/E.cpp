#include <bits/stdc++.h>

using ll = long long;
const int maxn = 2505;

std::vector<int>upd[maxn];
int w[maxn],D[maxn][maxn],ref[maxn],n,m,k;
char G[maxn][maxn];
ll ans;

struct data {
	int L[7] = {0},R[7] = {0}, ans = 0, sum = 0;
};
data New(int x) {
	data d; if (x <= k) { d.L[x] = d.R[x] = 1; } d.sum = x; d.ans = (x == k);
	return d;
}

data merge(data x,data y) {
	data z;
	std::memcpy(z.L,x.L,28);
	std::memcpy(z.R,y.R,28);
	z.ans = x.ans + y.ans;
	z.sum = x.sum + y.sum;
	for (int i = 0; i <= k; ++ i) z.ans += x.R[i] * y.L[k - i];
	for (int i = 0; i + x.sum <= k; ++ i) z.L[i + x.sum] += y.L[i];
	for (int i = 0; i + y.sum <= k; ++ i) z.R[i + y.sum] += x.R[i];
	return z;
}
	

struct segmentTree {
	data sum[maxn<<2];
	void update(int x) { sum[x] = merge(sum[x<<1],sum[x<<1|1]); }
	void build(int l,int r,int rt) {
		if (l == r) {
			w[l] = 0;
			ref[l] = rt;
			sum[rt] = New(0);
			return;
		} int mid = (l+r)>>1;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		update(rt);
	}
	void add(int x) {
		if (w[x] > k) return;
		int p = ref[x];
		w[x] ++;
		sum[p] = New(w[x]);
		p >>= 1;
		while (p) { update(p); p>>=1; }
	}
}seg;

void find_next(int i,int j,int cnt) {
	if ((i > n) || (!i) || (!cnt)) return;
	int x = D[i][j];
	if (!x) return;
	upd[x].push_back(j);
	find_next(x + 1, j, cnt - 1);
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= n; ++ i) scanf("%s",G[i] + 1);
	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= m; ++ j) {
			if (G[i][j] == '1') D[i][j] = i;
			else D[i][j] = D[i+1][j];
		}
	}
	for (int l = 1; l <= n; ++ l) {
		for (int r = l; r <= n; ++ r) upd[r].clear();
		seg.build(1,m,1);
		for (int j = 1; j <= m; ++ j)  find_next(l,j,k + 1); 
		for (int r = l; r <= n; ++ r) {
			for (auto x:upd[r]) { seg.add(x);  }
			ans += seg.sum[1].ans;
		}
	} printf("%lld",ans);
	return 0;
}