/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 35000;
const int maxk = 100;
int n, k, l = 1, r, a[maxn + 5], last[maxn + 5], pre[maxn + 5], suf[maxn + 5];
ll ans, dp[maxk + 5][maxn + 5];
ll query(int ql, int qr) {
	while(l < ql) {
		if(suf[l] <= r) ans -= suf[l] - l;
		l ++;
	}
	while(l > ql) {
		l --;
		if(suf[l] <= r) ans += suf[l] - l;
	}
	while(r < qr) {
		r ++;
		if(pre[r] >= l) ans += r - pre[r];
	}
	while(r > qr) {
		if(pre[r] >= l) ans -= r - pre[r];
		r --; 
	} 
	return ans;
}
void solve(int k, int l, int r, int L, int R) {
	if(l > r) return ;
	int mid = l + r >> 1, p = L;
	rep(i, L, min(R, mid - 1)) if(chkmn(dp[k][mid], dp[k - 1][i] + query(i + 1, mid))) p = i;
	solve(k, l, mid - 1, L, p), solve(k, mid + 1, r, p, R); 
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d",&n, &k), memset(dp, 127, sizeof dp);
	rep(i, 1, n) scanf("%d", &a[i]), pre[i] = last[a[i]], suf[last[a[i]]] = i, last[a[i]] = i;
	rep(i, 1, n) if(!suf[i]) suf[i] = n + 1;
	rep(i, 1, n) dp[1][i] = query(1, i);
	rep(i, 2, k) solve(i, 1, n, 1, n); 
	printf("%lld\n", dp[k][n]);
	return 0;
}