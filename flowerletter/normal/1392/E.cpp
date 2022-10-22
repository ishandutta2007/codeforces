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
const int maxn = 25;
int n, q, t[maxn * 2 + 5];
ll a[maxn + 5][maxn + 5]; 
vector<P> ans;
void dfs(int x, int y, ll k) {
	ans.pb({x, y});
	if(x == 1 && y == 1) return assert(!k), void();
	if(x == 1) return dfs(x, y - 1, k - a[x][y - 1]);
	if(y == 1) return dfs(x - 1, y, k - a[x - 1][y]);
	ll u = a[x - 1][y], v = a[x][y - 1];
	if(k & u) dfs(x - 1, y, k - u);
	else if(k & v) dfs(x, y - 1, k - v);
	else if(!u) dfs(x - 1, y, k - u);
	else if(!v) dfs(x, y - 1, k - v);
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i, 1, 2 * n) t[i] = i;
	rep(i, 1, n) {
		rep(j, 1, n) {
			ll c = 1ll << i + j - 2;
			if(t[i + j] & 1) {
				cout << (a[i][j] = c) << ' ';
			}
			else {
				cout << 0 << ' ';
			}
			t[i + j] ++;
		}
		cout << endl;
	}
	cin >> q;
	while(q --) {
		ll k; cin >> k;
		ans.clear();
		dfs(n, n, k - a[n][n]);
		reverse(all(ans));
		for(auto x : ans) cout << x.fi << ' ' << x.se << endl; 
	}
	
	return 0;
}