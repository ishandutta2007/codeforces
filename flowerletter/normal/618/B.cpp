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
const int maxn = 50;
int n, a[maxn + 5][maxn + 5], ans[maxn + 5], vis[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) rep(j, 1, n) scanf("%d", &a[i][j]);
	rep(i, 1, n) {
		int p = -1;
		rep(j, 1, n) {
			int flag = 1;
			rep(k, 1, n) if(k != j && !vis[k] && a[j][k] != i) flag = 0;
			if(flag) p = j;
		}
		vis[p] = 1, ans[p] = i;
	}
	rep(i, 1, n) printf("%d ", ans[i]);
	return 0;
}