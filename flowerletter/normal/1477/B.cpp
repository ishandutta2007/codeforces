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

const int maxn = 2e5;
int T, n, q, l[maxn + 5], r[maxn + 5];
char s[maxn + 5], t[maxn + 5];
struct Segment {
	#define ls rt << 1
	#define rs rt << 1 | 1
	int sum[maxn << 2], tag[maxn << 2], size[maxn << 2];
	void pushup(int rt) {
		sum[rt] = sum[ls] + sum[rs];
	}
	void seta(int rt, int k) {
		tag[rt] = k;
		sum[rt] = size[rt] * k;
	}
	void pushdown(int rt) {
		if(tag[rt] != -1) {
			seta(ls, tag[rt]), seta(rs, tag[rt]);
			tag[rt] = -1;
		}
	}
	int qry(int rt, int l, int r, int L, int R) {
		if(l >= L && r <= R) return sum[rt];
		int mid = l + r >> 1;pushdown(rt);
		if(R <= mid) return qry(ls, l, mid, L, R);
		else if(L > mid) return qry(rs, mid + 1, r, L, R);
		else return qry(ls, l, mid, L, R) + qry(rs, mid + 1, r, L, R);
	} 
	void cover(int rt, int l, int r, int L, int R, int k) {
		if(l >= L && r <= R) {seta(rt, k);return ;}
		int mid = l + r >> 1;pushdown(rt);
		if(R <= mid) cover(ls, l, mid, L, R, k);
		else if(L > mid) cover(rs, mid + 1, r, L, R, k);
		else cover(ls, l, mid, L, R, k), cover(rs, mid + 1, r, L, R, k);
		pushup(rt);
	}
	void build(int rt, int l, int r) {
		size[rt] = r - l + 1, tag[rt] = -1;
		if(l == r) {
			sum[rt] = t[l] == '1';
			return ;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(rt);
	}
	bool check(int rt, int l, int r) {
		if(l == r) return sum[rt] == (s[l] == '1');
		int mid = l + r >> 1;pushdown(rt);
		return check(ls, l, mid) & check(rs, mid + 1, r);
	}
}mjy;
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d%s%s", &n, &q, s + 1, t + 1);
		rep(i, 1, q) scanf("%d%d", &l[i], &r[i]);
		mjy.build(1, 1, n);
		int flag = 1;
		per(i, q, 1) {
			int cnt1 = mjy.qry(1, 1, n, l[i], r[i]), cnt0 = (r[i] - l[i] + 1) - cnt1;
			if(cnt0 == cnt1) {
				flag = 0;
				break;
			}
			if(cnt0 < cnt1) mjy.cover(1, 1, n, l[i], r[i], 1);
			else mjy.cover(1, 1, n, l[i], r[i], 0);
		}
		if(flag) puts(mjy.check(1, 1, n) ? "YES" : "NO");
		else puts("NO");
	}
	return 0;
}