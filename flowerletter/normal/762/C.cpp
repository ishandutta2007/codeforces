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
const int maxn = 1e5;
int n, m, nxt[maxn + 5][26], lst[maxn + 5][26];
int p[maxn + 5], q[maxn + 5];
char s[maxn + 5], t[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> s + 1 >> t + 1;
	n = strlen(s + 1), m = strlen(t + 1);
	rep(i, 1, n) {
		rep(j, 0, 25) lst[i][j] = lst[i - 1][j];
		lst[i][s[i] - 'a'] = i;
	}
	rep(i, 0, 25) nxt[n + 1][i] = n + 1;
	per(i, n, 1) {
		rep(j, 0, 25) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
	rep(i, 1, m) {
		p[i] = p[i - 1] <= n ? nxt[p[i - 1] + 1][t[i] - 'a'] : n + 1;
	}
	q[m + 1] = n + 1;
	per(i, m, 1) {
		q[i] = q[i + 1] ? lst[q[i + 1] - 1][t[i] - 'a'] : 0;
	}
	int len = 0;
	P l = {-1, -1};
	per(i, m + 1, 1) {
		int pos = min(lower_bound(p + 1, p + m + 1, q[i]) - p - 1, i - 1);
		if(q[i] == 0) break;
		if(chkmx(len, m - i + 1 + pos)) l = {pos, i};
	}
	if(!len) cout << "-\n";
	else {
		rep(i, 1, l.fi) putchar(t[i]);
		rep(i, l.se, m) putchar(t[i]);
		putchar('\n');
	}
	return 0;
}