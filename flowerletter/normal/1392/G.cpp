#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e6;
const int maxk = 20;
const int maxs = 1 << 20;
const int inf = 1e9;
int n, m, k, f[maxk + 5][maxs + 5];
int id[maxk + 5];
int sta[maxn + 5], qry[maxn + 5];
char s[maxn + 5], t[maxn + 5];
struct Node {
	int a[maxk + 5];
	friend Node operator + (Node x, Node y) {
		Node z; 
		rep(i, 1, k) z.a[i] = y.a[x.a[i]];
		return z;
	}
};
inline int rnd(int l, int r) {return hua() % (r - l + 1) + l;}
//P mn[maxs + 5][maxs + 5];
//int cnt[maxs + 5];
//void ins(int s, int id) {
//	int a = s & maxs, b = s >> 10;
//	rep(i, 0, maxs) {
//		chkmn(mn[a][i], {cnt[i ^ b], id});
//	}
//}
//P qry(int s) {
//	int a = s & maxs, b = s >> 10;
//	P ans = {inf, inf};
//	rep(i, 0, maxs) {
//		P tmp = mn[i][b]; tmp.fi += cnt[i ^ a];
//		chkmn(ans, tmp);
//	}
//	return ans;
//}
int main() {
// 	freopen("in.txt", "r", stdin);
//	rep(i, 1, maxs) cnt[i] = cnt[i ^ lb(i)] + 1;
//	rep(s, 0, maxs) rep(t, 0, maxs) mn[s][t] = {inf, inf};
	n = read(), m = read(), k = read();
	scanf("%s%s", s + 1, t + 1);
    // int st = clock();
    // n = 1e6, m = 1, k = 20;
    // rep(i, 1, k) s[i] = rnd(0, 1) + '0';
    // rep(i, 1, k) t[i] = rnd(0, 1) + '0';
	rep(i, 1, k) s[i] -= '0', t[i] -= '0';
	rep(i, 1, k) id[i] = i;
	Node cur, curr;
	rep(i, 1, k) cur.a[i] = curr.a[i] = i;
	A<3> ans = {inf, inf, inf};
	rep(i, 1, k) sta[0] |= s[i] << i - 1; 
	rep(i, 1, n) {
		Node tmp;
		int a = read(), b = read();
        // int a = rnd(1, k), b = rnd(1, k);
		rep(i, 1, k) tmp.a[i] = i == a || i == b ? a + b - i : i;
		cur = tmp + cur;
		curr = tmp + curr;
		int S = 0, T = 0;
		rep(i, 1, k) {
			S |= s[i] << cur.a[i] - 1;
			T |= t[i] << curr.a[i] - 1;
		}
		sta[i] = S, qry[i] = T;
//		if(i >= m) ins(sta[i - m], i - m + 1);
//		P x = qry(T);
//		chkmn(ans, {x.fi, x.se, i});
	}
// 	cout << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
	rep(s, 0, (1 << k) - 1) rep(i, 0, k) f[i][s] = inf;
	per(i, n, 0) f[0][sta[i]] = i;
	rep(i, 1, k) {
		rep(s, 0, (1 << k) - 1) {
			f[i][s] = f[i - 1][s];
			rep(j, 1, k) chkmn(f[i][s], f[i - 1][s ^ 1 << j - 1]);
		}
	}
// 	cout << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
	rep(i, 1, n) {
		rep(j, 0, k) if(f[j][qry[i]] <= i - m) {
			chkmn(ans, {j, f[j][qry[i]] + 1, i});
			break;
		}
	}
// 	cout << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
	cout << (k - ans[0]) << '\n' << ans[1] << ' ' << ans[2] << '\n';
	return 0;
}