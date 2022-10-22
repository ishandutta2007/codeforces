/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fir first
#define sec second
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int maxn = 1e5;
int T, n, u, v, a[maxn + 5], du[maxn + 5], id[maxn + 5];

inline bool cmp(int x, int y) {return a[x] > a[y];}

int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) id[i] = i, du[i] = 0, scanf("%d", &a[i]);
		rep(i, 2, n) scanf("%d%d", &u, &v), du[u]++, du[v]++;
		sort(id + 1, id + n + 1, cmp);
		int nw = 1, used = 1;ll ans = 0;
		rep(i, 1, n) ans += a[i]; 
		rep(i, 1, n - 1) {
			printf("%lld%c", ans , " \n"[i == n - 1]);
			while(used == du[id[nw]] && nw <= n) nw++, used = 1;
			if(nw <= n) ans += a[id[nw]], used++;
		}
	}
	return 0;
}