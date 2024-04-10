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
const int maxn = 1e5;
int T, n, a[maxn + 5], b[maxn + 5], cnt[maxn + 5][2];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i], cnt[a[i]][i & 1] ++;
		sort(b + 1, b + n + 1);
		int flag = 1;
		rep(i, 1, maxn) {
			int l = lower_bound(b + 1, b + n + 1, i) - b;
			int r = upper_bound(b + 1, b + n + 1, i) - b - 1;
			int x = ((r + 1) / 2 - l / 2), y = (r / 2 - (l - 1) / 2);
			if(x != cnt[i][1] || y != cnt[i][0]) {
				flag = 0;
				puts("NO");
				break;
			}
		}
		if(flag) puts("YES");
		rep(i, 1, maxn) cnt[i][0] = cnt[i][1] = 0;
	}
	return 0;
}