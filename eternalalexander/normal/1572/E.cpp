#include <bits/stdc++.h>

using ll = long long;
const int maxn = 205;
int n,k;
ll x[maxn],y[maxn],S[maxn][maxn];
std::pair<int,ll> f[maxn][maxn];

ll area(int l,int r) {
	if (r <= l + 1) return 0;
	if (S[l][r]) return S[l][r];
	for (int i = l; i < r; ++ i) S[l][r] += x[i] * y[i + 1] - y[i] * x[i + 1];
	S[l][r] += x[r] * y[l] - x[l] * y[r];
	return S[l][r];
}

ll tria(int i,int j,int k) {
//	printf("tria %d %d %d = %lld\n",i,j,k,x[i] * y[j] - x[j] * y[i] + x[j] * y[k] - x[k] * y[j] + x[k] * y[i] - y[k] * x[i]);
	return x[i] * y[j] - x[j] * y[i] + x[j] * y[k] - x[k] * y[j] + x[k] * y[i] - y[k] * x[i];
}

std::pair<int,ll>cond(std::pair<int,ll>a,ll lim) {
	if (a.second >= lim) { a.first ++; a.second = 0; }
	return a;
}

int check(ll lim) {
	for (int i = n; i >= 1; i --) 
	for (int j = i + 2; j <= n; j ++) {
		f[i][j] = cond({0,area(i,j)},lim);
		for (int k = i + 1; k < j; ++ k) {
			f[i][j] = std::max(f[i][j],cond({f[i][k].first + f[k][j].first,
									f[i][k].second + f[k][j].second + tria(i,k,j)},lim));
		}
	} return f[1][n].first >= k;
}

int main() {
	scanf("%d%d",&n,&k); k ++;
	for (int i = 1; i <= n; ++ i) 
		scanf("%lld%lld",&x[i],&y[i]);
	ll l = 1, r = 1e18, ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) { ans = mid; l = mid + 1; }
		else r = mid - 1;
	} printf("%lld",ans);
	return 0;
}