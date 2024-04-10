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

const int maxn = 1e5, lg = 100, maxw = 4;
const ll inf = 1e18;
ll n;
int m, lim;
char s[maxn + 5];

struct matrix {
	ll a[4][4];
	matrix(){rep(i, 0, 3) rep(j, 0, 3) a[i][j] = inf;}
	friend matrix operator * (matrix a, matrix b) {
		matrix ans;
		rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) chkmin(ans[i][j], a[i][k] + b[k][j]);
		return ans;
	}
	bool is() {
		rep(i, 0, 3) rep(j, 0, 3) if(a[i][j] < n) return false;
		return true;
	}
	ll* operator [] (int x) {return a[x];}
}dis;
struct trie {
	int Nodecnt = 1;
	int son[maxn * lg + 5][4];
	void insert(int l, int r) {
		int p = 1;
		rep(i, l, r) {
			if(!son[p][s[i]]) son[p][s[i]] = ++Nodecnt;
			p = son[p][s[i]];
		}
	}
	void dfs(int p, int begin, int last,int dep) {
		if(!p) {
			chkmin(dis[begin][last], (ll)dep);
			return ;
		}
		rep(i, 0, 3) dfs(son[p][i], begin, i, dep + 1);
	}
}mjy;
matrix fpow(matrix a, ll b) {
	matrix ans = a; b--;
	for(; b; b >>= 1, a = a * a) if(b & 1) ans = ans *a;
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%lld%s", &n, s + 1);
	m = strlen(s + 1), lim = log2(n) + 3;
	rep(i, 1, m) s[i] -= 'A';
	rep(i, 1, m) mjy.insert(i, min(i + lim - 1, m));
	rep(i, 0, 3) mjy.dfs(mjy.son[1][i], i, i, 0);
	ll l = 1, r	= n, ans = -1;
	while(l <= r) {
		ll mid = l + r >> 1;
		if(fpow(dis, mid).is()) ans = mid, r = mid - 1;
		else l = mid + 1; 
	}
	printf("%lld\n", ans);
	return 0;
}