/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2e5;
int T, n, ans, a[maxn + 5], vis[maxn + 5];
vector<int> s, t;
void solve(vector<int> s, vector<int> t) {
	while(1) {
		random_shuffle(all(t));
		int flag = 1;
		rep(i, 0, sz(s) - 1) flag &= s[i] != t[i];
		if(flag) {
			rep(i, 0, sz(s) - 1) a[s[i]] = t[i];
			return ;
		}
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T--) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) {
			if(vis[a[i]]) s.push_back(i);
			else ans ++, vis[a[i]] = 1;
		}
		rep(i, 1, n) if(!vis[i]) t.push_back(i);
		if(sz(s) == 1 && sz(t) == 1 && s[0] == t[0]) {
			int u = s[0], v = a[s[0]];
			a[u] = v;
			rep(i, 1, u - 1) if(a[i] == v) s[0] = i;
		}
		solve(s, t);
		cout << ans << '\n';
		rep(i, 1, n) cout << a[i] << ' '; puts("");
		ans = 0, s.clear(), t.clear();
		rep(i, 1, n) vis[i] = 0;
	}
	return 0;
}