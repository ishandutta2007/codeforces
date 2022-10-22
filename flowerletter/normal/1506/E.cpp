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
const int maxn = 2e5;
int T, n, a[maxn + 5], ans1[maxn + 5], ans2[maxn + 5];
struct dsu {
	int fa[maxn + 5];
	void clear() {rep(i, 1, n) fa[i] = i;}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void merge(int u, int v) {
		if(!v || v == n + 1) return ;
		int x = find(u), y = find(v);
		fa[x] = y;
	} 
}s, t;
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n), s.clear(), t.clear();
		rep(i, 1, n) scanf("%d", &a[i]), ans1[i] = 0, ans2[i] = 0;
		rep(i, 1, n) if(a[i] != a[i - 1]) ans1[i] = ans2[i] = a[i], s.merge(a[i], a[i] + 1), t.merge(a[i], a[i] - 1);
		rep(i, 1, n) if(!ans1[i]) {
			ans1[i] = s.find(1);
			s.merge(ans1[i], ans1[i] + 1);
			ans2[i] = t.find(a[i]);
			t.merge(ans2[i], ans2[i] - 1);
		}
		rep(i, 1, n) printf("%d%c", ans1[i], " \n"[i == n]);
		rep(i, 1, n) printf("%d%c", ans2[i], " \n"[i == n]);
	}
	return 0;
}