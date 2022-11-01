#include <bits/stdc++.h>
#define INF (1<<29)
#define mod 1000000007
#define N 250
#define x1 gtmcjb
#define y1 gtmcjb2
using namespace std;
typedef long long LL;
inline int rd() {int r;scanf("%d",&r);return r;}

int vis[N][N], dp[N][N], x[N], y[N], n;

void inc(int &x,int y) {x=(x+y)%mod;}

LL Cross(int a,int b,int c){
	return 1LL * (x[a]-x[c]) * (y[b]-y[c]) - 1LL * (x[b]-x[c]) * (y[a]-y[c]);
}

int F(int l,int r) {
	if (l+1 == r) return 1;
	if (vis[l][r]) return dp[l][r];
	int ret = 0;
	vis[l][r] = 1;
	
	
	for (int i=l+1;i<r;i++)
		if (Cross(l, i, r) > 0)
			inc(ret, 1LL * F(l,i) * F(i,r) % mod);
	
	return dp[l][r] = ret;
}

void solve() {
	n = rd();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) vis[i][j] = dp[i][j] = 0;
	for (int i=1;i<=n;i++) x[i] = rd(), y[i] = rd();
	
	long long sum = 0;
	for (int i=2;i<n;i++) {
		sum += Cross(i, i+1, 1);
	}
	
	if (sum < 0) {
		for (int i=1;i<=n/2;i++)
			swap(x[i], x[n-i+1]), swap(y[i], y[n-i+1]);
	}
	
	printf("%d\n", F(1,n));
	return ;
}

int main() {
	solve();
	return 0;
}