#include <bits/stdc++.h>

using ll = long long;

const int lim = 5000;
const int maxn = 100000;

int a[maxn],isp[maxn],P[maxn],cnt,k,tl,prd,cw;

void solve(int l,int r,int c) {
	if (l >= r) return;
	int mid = (l+r) >> 1;
	for (int i = l; i <= mid; ++ i) a[i] *= P[c];
	solve(l,mid,c+1);
	solve(mid+1,r,c+1);
}

void dfs(int c,ll p) {
	if (p > 2 * k * k) return;
	a[++tl] = p;
	for (int i = 0; c + i <= cnt; ++ i) dfs(c + i, p * P[c + i]);
}

int count(int x) {
	for (int i = 1; i <= cnt; ++ i) if (x%P[i]) return 0;
	return 1;
}

int main() {
	scanf("%d",&k);
	for (int i = 1; i <= k; ++ i) a[i] = 1;
	for (int i = 2; i <= lim; ++ i) isp[i] = 1;
	for (int i = 2; i <= lim; ++ i) {
		if (isp[i]) P[++cw] = i;
		for (int j = i + i; j <= lim; j += i) isp[j] = 0;
	}
	int prd = 1; cnt = 0;
	while (P[cnt + 1] * prd <= k) { prd *= P[++cnt]; }
	dfs(1,1);
	std::sort(a+1,a+tl+1,[](int a,int b) { return count(a) > count(b); });
	for (int i = 1; i <= k; ++ i) printf("%d ",a[i]);
	return 0;
}