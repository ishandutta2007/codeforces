/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.zie())
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmax(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 3000;

int n, u[maxn + 5], v[maxn + 5], w[maxn + 5], fa[maxn + 5], size[maxn + 5], id[maxn + 5	];
ll all, sum[maxn + 5];

int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 2, n) scanf("%d%d%d", &u[i], &v[i], &w[i]), id[i] = i;
	rep(i, 1, n) scanf("%lld", &sum[i]), fa[i] = i, size[i] = 1, all += sum[i];
	sort(id + 2, id + n + 1, [=](int x, int y) {return w[x] < w[y];});
	rep(i, 2, n) {
		int fx = find(u[id[i]]), fy = find(v[id[i]]);
		fa[fx] = fy, sum[fy] += sum[fx], size[fy] += size[fx];
		if(size[fy] > all - sum[fy]) {
			printf("%d\n", w[id[i]]);
			return 0;
		}
	} 
	printf("%d\n", w[id[n]]);
	return 0;
}