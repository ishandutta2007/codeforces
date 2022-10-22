/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}

const int maxn = 3e5;

int n, h[maxn + 5], b[maxn + 5];
ll dp[maxn + 5], c[maxn + 5], pr[maxn + 5];
void solve(int l, int r) {
	if(l == r) return ;
	int mid = l + r >> 1;
	solve(l, mid); 
	//if(l == 0 && r == 1)cout << l << ' ' << r << endl; 
	//if(l == 0 && r == 1)rep(i, l, mid) cout << dp[i] << ' ';
	//if(l == 0 && r == 1)puts("");
	int mn = 1e9, val = -1; pr[mid + 1] = -1e18;
	rep(i, mid + 1, r + 1) c[i] = -1e18;
	for(int i = mid, j = mid; i > l; i--) {
		pr[i] = max(pr[i + 1], dp[i]);
		//if(l == 0 && r == 5) cout << pr[i] << " \n"[i == l + 1];
		if(chkmn(mn, h[i])) val = b[i];
		while(j + 1 <= r && h[j + 1] >= mn) j++;
		chkmx(c[j], dp[i - 1] + val);
		//if(l == 0 && r == 5) cout << i << ' ' << j << endl;
	}
	pr[l] = max(pr[l + 1], dp[l]);
	per(i, r, mid + 1) chkmx(c[i], c[i + 1]), chkmx(dp[i], c[i]);
	//if(l == 0 && r == 5) rep(i, mid + 1, r) cout << dp[i] << " \n"[i ==r];
	mn = 1e9, val = -1;
	for(int i = mid + 1, j = mid + 1; i <= r; i++) {
		if(chkmn(mn, h[i])) val = b[i];
		while(j - 1 > l && h[j - 1] >= mn) j--;
		chkmx(dp[i], pr[j - 1] + val);//, chkmx(dp[i], dp[mid] + val);
		//if(l == 0 && r == 1) cout << i << ' ' << j << ' ' << pr[j - 1] + val << endl;
	}
	//if(l == 0 && r == 1) rep(i, mid + 1, r) cout << dp[i] << ' ';
	//if(l == 3 && r == 4) exit(0);
	solve(mid + 1, r);
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &h[i]), dp[i] = -1e18;
	rep(i, 1, n) scanf("%d", &b[i]);
	solve(0, n);
	//rep(i, 1, n) cout << dp[i] << ' ';
	printf("%lld\n", dp[n]);
	return 0;
}