#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 2e5;
int n, m, a[maxn + 5], lim[maxn + 5], cnt[maxn + 5];
struct Node {
	int k;
	vector<int> s;
	ll sum;
}b[maxn + 5];
struct Segment {
	int a[maxn + 5];
	#define ls u << 1
	#define rs u << 1 | 1
	int mn[maxn* 4], tag[maxn * 4];
	void pushup(int u) {
		mn[u] = min(mn[ls], mn[rs]);
	}
	void seta(int u, int k) {
		tag[u] += k, mn[u] += k;
	}
	void pushdown(int u) {
		if(tag[u]) seta(ls, tag[u]), seta(rs, tag[u]), tag[u] = 0;
	}
	void update(int u, int l, int r, int ql, int qr, int k) {
		if(l >= ql && r <= qr) return seta(u, k), void();
		int mid = l + r >> 1; pushdown(u);
		if(qr <= mid) update(ls, l, mid, ql, qr, k);
		else if(ql > mid) update(rs, mid + 1, r, ql, qr, k);
		else update(ls, l, mid, ql, qr, k), update(rs, mid + 1, r, ql, qr, k);
		pushup(u);
	}
	void clear(int n) {
		rep(i, 1, 4 * n) mn[i] = tag[i] = 0;
	}
}ds;
int main() {
	//freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read(), m = read();
		ds.clear(m + 1);
		rep(i, 1, m + 1) cnt[i] = 0;
		rep(i, 1, n) a[i] = read();
		rep(i, 1, m) {
			b[i].k = read(); b[i].sum = 0;
			b[i].s.resize(b[i].k);
			rep(j, 0, b[i].k - 1) b[i].sum += (b[i].s[j] = read());
		}
		sort(a + 1, a + n + 1);
		int d = n - m;
		rep(i, 1, m) a[i] = a[i + d];
		rep(i, 1, m) {
			lim[i] = lower_bound(a + 1, a + m + 1, 1.0 * b[i].sum / b[i].k) - a;
			cnt[lim[i]] --;
		}
		per(i, m, 1) cnt[i] += cnt[i + 1];
		per(i, m + 1, 1) cnt[i] += m + 1 - i, ds.update(1, 1, m + 1, i, i, cnt[i]);
		rep(i, 1, m) {
			ds.update(1, 1, m + 1, 1, lim[i], 1);
			rep(j, 0, b[i].k - 1) {
				int nwlim = lower_bound(a + 1, a + m + 1, 1.0 * (b[i].sum - b[i].s[j]) / (b[i].k - 1)) - a;
				ds.update(1, 1, m + 1, 1, nwlim, -1);
				putchar(ds.mn[1] == 0 ? '1' : '0');
				ds.update(1, 1, m + 1, 1, nwlim, 1);
			}
			ds.update(1, 1, m + 1, 1, lim[i], -1);
		}
		putchar('\n');
	}
	return 0;
}