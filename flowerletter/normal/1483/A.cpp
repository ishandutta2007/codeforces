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
const int maxn = 1e5;
int T, n, m, k[maxn + 5], ans[maxn + 5], cnt[maxn + 5];
vector<int> f[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) cnt[i] = 0;
		rep(i, 1, m) {
			scanf("%d", &k[i]);
			f[i].clear(), f[i].resize(k[i]);
			rep(j, 0, k[i] - 1) scanf("%d", &f[i][j]);
			if(k[i] == 1) cnt[f[i][0]]++;
		}
		int flag = 1;
		rep(i, 1, n) if(cnt[i] > (m + 1) / 2) {puts("NO"), flag = 0; break;}
		if(flag) {
			rep(i, 1 ,n) cnt[i] = 0;
			rep(i, 1, m) if(k[i] == 1) cnt[ans[i] = f[i][0]]++;
			rep(i, 1, m) if(k[i] != 1) {
				rep(j, 0, k[i] - 1) {
					int x = f[i][j];
					if(cnt[x] == (m + 1) / 2) continue;
					cnt[ans[i] = x]++; break;
				}
			}
			puts("YES");
			rep(i, 1, m) printf("%d ", ans[i]);
			puts("");
		}
	}
	return 0;
}