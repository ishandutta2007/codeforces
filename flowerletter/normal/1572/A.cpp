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
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2e5;
const int inf = 1e9;
int T, n, deg[maxn + 5], f[maxn + 5];
int cnt, head[maxn + 5];
struct Edge {
	int to, next;
}e[maxn + 5];
void add(int u, int v) {
	e[++ cnt] = {v, head[u]}, head[u] = cnt;
}
void clear() {
	cnt = 0;
	rep(i, 1, n) head[i] = 0;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> n;
		clear();
		queue<int> q;
		rep(i, 1, n) {
			f[i] = 0;
			cin >> deg[i];
			rep(j, 1, deg[i]) {
				int x;
				cin >> x;
				add(x, i);
			}
			if(!deg[i]) q.push(i);
		}
		int ans = 0, tot = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			chkmx(ans, f[u]), tot ++;
			trv(i, u, v) {
				if(-- deg[v] == 0) q.push(v);
				chkmx(f[v], f[u] + (u > v));
			}
		}
		cout << (tot == n ? ans + 1 : -1) << '\n';
	}
	return 0;
}