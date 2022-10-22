#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int maxn = 1e6;
const int lg = 20;
int n, m, q, ql, qr, mx[maxn + 5], lg2[maxn + 5];
int st[lg + 1][maxn + 5];
char s[maxn + 5];
vector<int> a[maxn + 5], f[maxn + 5], l[maxn + 5];
int qry(int ql, int qr) {
	int k = lg2[qr - ql + 1];
	return max(st[k][ql], st[k][qr - (1 << k) + 1]);
}
void init() {
	rep(i, 2, m) lg2[i] = lg2[i >> 1] + 1;
	rep(i, 1, m) st[0][i] = mx[i];
	rep(i, 1, lg) rep(j, 1, m - (1 << i) + 1) {
		st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> s + 1;
		a[i].resize(m + 1), f[i].resize(m + 1), l[i].resize(m + 1);
		rep(j, 1, m) a[i][j] = s[j] == '.'; 
	} 
	rep(i, 1, n) rep(j, 1, m) {
		if(a[i][j]) {
			if(i == 1 || j == 1) f[i][j] = 1;
			else f[i][j] = min(f[i - 1][j], f[i][j - 1]);
		} 
		else f[i][j] = j + 1;
	}
	rep(i, 2, n) rep(j, 2, m) {
		chkmx(mx[j], min(f[i - 1][j], f[i][j - 1]));
	}
	init();
	for(cin >> q; q; q --){
		cin >> ql >> qr;
		puts(qry(ql, qr) <= ql ? "YES" : "NO");
	}
	return 0;
}