/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
 
const int maxn = 1e5;
 
int n, a[maxn + 5], col[maxn + 5], dp[maxn + 5];
vector<int> s, p[maxn + 5];
struct Segment {
	#define ls rt << 1
	#define rs rt << 1 | 1
	int tag[maxn * 4], mn[maxn * 4];
	void add() {tag[1]++, mn[1]++;}
	void pushup(int rt) {
		mn[rt] = min(mn[ls], mn[rs]);
	}
	void pushdown(int rt) {
		mn[ls] += tag[rt], mn[rs] += tag[rt];
		tag[ls] += tag[rt], tag[rs] += tag[rt];
		tag[rt] = 0; 
	}
	void update(int rt, int l, int r, int p, int k) {
		if(l == r) {
			mn[rt] = k;
			return ;
		}
		int mid = l + r >> 1; pushdown(rt);
		if(p <= mid) update(ls, l, mid, p, k);
		else update(rs, mid + 1, r, p ,k);
		pushup(rt);
	}
	int query(int rt, int l, int r, int L , int R) {
		if(L > R) return 1e9;
		if(l >= L && r <= R) return mn[rt];
		int mid = l + r >> 1; pushdown(rt);
		if(R <= mid) return query(ls, l, mid, L, R);
		else if(L > mid) return query(rs, mid + 1, r, L, R);
		else return min(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
}mjy;
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	for(int l = 1, r; l <= n; l = r + 1) {
		r = l;
		while(r + 1 <= n && a[r + 1] == a[l]) r++;
		p[a[l]].push_back(sz(s));
		s.push_back(a[l]);
	}
	if(sz(s) == 1) {
		puts("1");
		return 0;
	}
	mjy.tag[1] = 1e9, mjy.update(1, 1, n, s[0], 2); 
	rep(i, 2, sz(s) - 1) {
		mjy.add();
		if(i) mjy.update(1, 1, n, s[i - 1], min({mjy.query(1, 1, n, 1, s[i] - 1), mjy.query(1, 1, n, s[i] + 1, n), mjy.query(1, 1, n, s[i], s[i]) - 1}));
	}
	cout << mjy.query(1, 1, n, 1, n);
	return 0;
}