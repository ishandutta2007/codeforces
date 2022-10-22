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
int T, n, m, x, h[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d%d", &n, &m, &x);
		rep(i, 1, n) scanf("%d", &h[i]);
		priority_queue<P> q;
		rep(i, 1, m) q.push(P{0, i});
		puts("YES");
		rep(i, 1, n) {
			P u = q.top(); q.pop();
			q.push(P{u.fi - h[i], u.se});
			printf("%d ", u.se);
		}
		puts("");
	}
	return 0;
}