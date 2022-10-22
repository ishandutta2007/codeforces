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
const int maxn = 1e4;
int T, n, ans[maxn + 5], vis[maxn + 5];
int cnt;
int ask(int x) {
	int p; cnt ++;
	cout << "? " << x << endl;
	cin >> p;
	return p;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> n; cnt = -1;
		rep(i, 1, n) vis[i] = 0;
		rep(i, 1, n) if(!vis[i]) {
			int nw = i, st = cnt;
			vector<int> s;
			while(1) {
				nw = ask(i);
				if(vis[nw]) break; 
				vis[nw] = 1;
				s.pb(nw);
			}
			int ed = cnt - 1, len = ed - st;
			int pos = (st + len - 1) / len * len - st;
			nw = i;
			rep(i, pos, sz(s) - 1) ans[nw] = s[i], nw = ans[nw];
			rep(i, 0, pos - 1) ans[nw] = s[i], nw = ans[nw];
		}
		cout << "! ";
		rep(i, 1, n) cout << ans[i] << ' '; cout << endl;
	}
	return 0;
}