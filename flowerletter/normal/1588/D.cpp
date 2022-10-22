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

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxc = 52;
const int maxn = 10;
const int maxm = 2 * maxc;
const int maxs = maxc * (1 << maxn);
const int inf = 1e9;
int n;
int f[maxc + 5][maxs + 5];
A<2> lst[maxc + 5][maxs + 5];
char s[maxm + 5];
vector<int> p[maxc + 5][maxn + 5];
vector<A<2>> sta;
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		sta.clear();
		rep(i, 0, maxc - 1) rep(j, 1, maxn) p[i][j].clear();
		n = read();
		rep(i, 1, n) {
			cin >> s + 1;
			int len = strlen(s + 1);
			rep(j, 1, len) {
				if(s[j] >= 'A' && s[j] <= 'Z') s[j] -= 'A';
				else s[j] -= 'a' - 26;
				p[s[j]][i].pb(j);
			}
		}
		auto pos = [&] (int c, int i, int s) {return sz(p[c][i]) <= (s >> i - 1 & 1) ? inf : p[c][i][s >> i - 1 & 1];};
		rep(i, 0, maxc - 1) {
			rep(s, 0, (1 << n) - 1) {
				int flag = 1;
				rep(j, 1, n) if(pos(i, j, s) == inf) {flag = 0; break;}
				if(flag) sta.pb({i, s});
			}
		}
		sort(all(sta), [&] (A<2> x, A<2> y) {
			rep(i, 1, n) if(pos(x[0], i, x[1]) != pos(y[0], i, y[1])) {
				return pos(x[0], i, x[1]) < pos(y[0], i, y[1]);
			}
			return false;
		});
		int ans = 0;
		A<2> ret = {-1, -1};
		for(auto x : sta) {
			f[x[0]][x[1]] = 1, lst[x[0]][x[1]] = {-1, -1};
			rep(i, 0, maxc - 1) {
				int flag = 1, s = 0;
				rep(j, 1, n) {
					if(pos(i, j, 0) >= pos(x[0], j, x[1])) flag = 0;
					else if(pos(i, j, 1 << j - 1) < pos(x[0], j, x[1])) s |= 1 << j - 1;
				}
				if(flag) if(chkmx(f[x[0]][x[1]], f[i][s] + 1)) lst[x[0]][x[1]] = {i, s}; 
			}
			for(int t = x[1]; t; t = (t - 1) & x[1]) {
				if(chkmx(f[x[0]][x[1]], f[x[0]][x[1] ^ t])) lst[x[0]][x[1]] = lst[x[0]][x[1] ^ t];
			}
			if(chkmx(ans, f[x[0]][x[1]])) ret = {x[0], x[1]};
		} 
		cout << ans << '\n';
		vector<char> s;
		while(ret != A<2>{-1, -1}) s.pb(ret[0] < 26 ? ret[0] + 'A' : (ret[0] - 26 + 'a')), ret = lst[ret[0]][ret[1]];
		reverse(all(s));
		for(auto c : s) cout << c; cout << '\n';
	}
	return 0;
}