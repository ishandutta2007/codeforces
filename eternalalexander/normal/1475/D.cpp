#include <bits/stdc++.h>

const int maxn = 6e5;

using ll = long long;
int n,t1,t2;
ll m,a[maxn],b[maxn],A[maxn],B[maxn];

void solve() {
	scanf("%d%lld",&n,&m);
	t1 = t2 = 0;
	const ll inf = 1e18;
	ll answ = inf;
	for (int i = 1; i <= n; ++ i) scanf("%lld",&a[i]);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&b[i]);
		if (b[i] == 1) A[++t1] = a[i];
		else B[++t2] = a[i];
	}
	std::sort(A+1,A+t1+1,[](ll a,ll b) { return a > b; }); 
	std::sort(B+1,B+t2+1,[](ll a,ll b) { return a > b; }); 
	for (int i = 1; i <= t1; ++ i) A[i] += A[i-1];
	for (int i = 1; i <= t2; ++ i) B[i] += B[i-1]; 
	for (int i = 0; i <= t1; ++ i) {
		int l = 0, r = t2, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (B[mid] + A[i] >= m) { ans = mid; r = mid - 1; }
			else l = mid + 1;
		} if (ans != -1) answ = std::min(answ, i + ans * 2ll);
	//	printf("%d %d\n",i,ans);
	} if (answ < inf) printf("%lld\n",answ);
	else puts("-1");
	return ;
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}