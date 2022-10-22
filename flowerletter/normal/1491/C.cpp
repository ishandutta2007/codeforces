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
const int maxn = 5000;
int T, n;
ll ans, a[maxn + 5], b[maxn + 5], c[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		ans = 0;
		rep(i, 1, n) a[i] = b[i] = c[i] = 0;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) {
			c[i] = c[i - 1] + b[i];
			int cur = max(1ll, a[i] - c[i]);
			if(i + a[i] + 1 <= n) b[i + a[i] + 1]--;
			if(i + 2 <= n) b[i + 2]++;
			if(c[i] > a[i] - 1) b[i + 1] += c[i] - a[i] + 1, b[i + 2] -= c[i] - a[i] + 1; 
			ans += cur - 1;
		}
		cout << ans << endl;
	} 
	return 0;
}