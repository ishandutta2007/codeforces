#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
int n,a[maxn],las[maxn],pre[maxn],ans,L[maxn],max[maxn<<2],dp[maxn];
int gmax(int x,int y) { return L[x] < L[y] ? x : y; }

void build(int l,int r,int rt) {
	if (l == r) { max[rt] = l; return ; }
	int mid = (l + r) >> 1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	max[rt] = gmax(max[rt<<1],max[rt<<1|1]);
}

int query(int l,int r,int L,int R,int rt) { 
	if (l > R || r < L || l > r) return 0;
	if (l <= L && R <= r) return max[rt];
	return gmax(query(l,r,L,(L+R)>>1,rt<<1),query(l,r,((L+R)>>1)+1,R,rt<<1|1));
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		if (!pre[a[i]]) pre[a[i]] = i;
		las[a[i]] = i;
	} 
	for (int i = 0; i <= n; ++ i) 
		L[i] = n + 1;
	for (int i = 1; i <= n; ++ i) 
		if (pre[i] != las[i]) { L[las[i]] = pre[i]; }
	build(1,n,1);
	for (int i = 1; i <= n; ++ i) {
		if (L[i] > n) dp[i] = dp[i - 1];
		else {
			int g = query(L[i] + 1,i - 1,1,n,1);
			if (L[i] < g && g < i) dp[i] = dp[g] + (i - g - 1);
			dp[i] = std::max(dp[i],dp[L[i] - 1] + (i - L[i] - 1));
		}
	} 
	printf("%d",dp[n]);
	return 0;
}