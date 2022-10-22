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
int T, n, a[maxn + 5];
struct Seg {
	#define ls rt << 1
	#define rs rt << 1 | 1 
	int sum[maxn * 4 + 5];
	void pushup(int rt) {sum[rt] = sum[ls] + sum[rs];}
	void update(int rt, int l, int r, int p, int k) {
		if(l == r) return sum[rt] = k, void();
		int mid = l + r >> 1;
		if(p <= mid) update(ls, l, mid, p, k);
		else update(rs, mid + 1, r, p, k);
		pushup(rt); 
	}
	int find(int rt, int l, int r, int L, int R) {
		if(!sum[rt] || L > R) return -1;
		if(l == r) return l;
		int mid = l + r >> 1;
		if(R <= mid) return find(ls, l, mid, L, R);
		else if(L > mid) return find(rs, mid + 1, r, L, R);
		else {
			int k = find(ls, l, mid, L, R);
			if(k == -1) return find(rs, mid + 1, r, L, R);
			else return k;
		}
	}
	void dfs(int rt, int l, int r) {
		if(l == r) return printf("%d ", sum[rt]), void();
		int mid = l + r >> 1;dfs(ls, l, mid), dfs(rs, mid + 1, r);
	}
}mjy;
struct ufs {
	int fa[maxn + 5];
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void clear() {rep(i, 1, n) fa[i] = i;}
}qwq, qaq;
int lst(int x) {return x == 1 ? n : x - 1;}
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n), qwq.clear(), qaq.clear();
		vector<int> ans;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) mjy.update(1, 1, n, i, __gcd(a[lst(i)], a[i]) == 1);
		int nw = 1;
		while(mjy.sum[1]){
			int p = mjy.find(1, 1, n, nw + 1, n);
			if(p == -1) p = mjy.find(1, 1, n, 1, nw);
			int nxt = qwq.find(p % n + 1);qwq.fa[p] = nxt;
			int last = qaq.find(lst(p)); qaq.fa[p] = last;
			mjy.update(1, 1, n, nxt, __gcd(a[nxt], a[last]) == 1);
			mjy.update(1, 1, n, p, 0);
			ans.push_back(p), nw = nxt;
		}
		printf("%d ", sz(ans));
		for(auto u : ans) printf("%d ", u); puts("");
	}
	return 0;
}