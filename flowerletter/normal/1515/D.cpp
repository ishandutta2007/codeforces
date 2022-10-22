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
const int maxn = 2e5;
int T, n, l, r, c[maxn + 5], cnt[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d%d", &n, &l, &r);
		rep(i, 1, n) scanf("%d",&c[i]), cnt[i] = 0;
		rep(i, 1, l) cnt[c[i]] --;
		rep(i, l + 1, n) cnt[c[i]] ++;
		int sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
		rep(i, 1, n) {
			if(cnt[i] & 1) {
				if(cnt[i] < 0) cnt1 ++;
				else cnt2 ++;
				cnt[i] = cnt[i] / 2 * 2;
			}
			if(cnt[i] < 0) sum1 += -cnt[i];
			else sum2 += cnt[i];
		}
		if(cnt1 < cnt2) swap(cnt1, cnt2), swap(sum1, sum2);
		int res = cnt2;
		cnt1 -= cnt2;
		int tmp = min(sum2, cnt1); tmp = tmp / 2 * 2;
		res += tmp, sum2 -= tmp, cnt1 -= tmp; 
		printf("%d\n", sum1 / 2 + sum2 / 2 + res + cnt1);
	}
	return 0;
}