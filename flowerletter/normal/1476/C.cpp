/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
 
const int maxn = 1e5;
int T, n;
ll a[maxn + 5], b[maxn + 5], c[maxn + 5];
ll dp[maxn + 5];
ll solve(int l, int r) {
	//cout << l << ' ' << r << endl;
	if(l == r) return 1;
	ll ans = 0;dp[l] = abs(a[l] - b[l]) + 1;
	rep(i, l + 1, r) {
		chkmx(ans, dp[i - 1] + c[i]);
		dp[i] = max((ll)abs(a[i] - b[i]) + 1, dp[i - 1] + c[i] + 1 - abs(a[i] - b[i]));
	}
	//rep(i, l, r) cout << dp[i] << endl;
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%lld", &c[i]);
		rep(i, 0, n - 1) scanf("%lld", &a[i]);
		rep(i, 0, n - 1) scanf("%lld", &b[i]);
		int last = 1;ll ans = 1;
		rep(i, 1, n) if(a[i] == b[i]) chkmx(ans, solve(last, i)), last = i;
		printf("%lld\n", max(ans, solve(last, n)));
	}
	return 0;
}