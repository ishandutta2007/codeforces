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

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		ll n, m;
		cin >> n >> m;
		vector<int> ans;
		auto solve = [&](ll n, ll m) {
			for(int i = 1; i * i <= n; i ++) if(n % i == 0) {
				if(m % i == 0) ans.pb(i);
				if(m % (n / i) == 0) ans.pb(n / i);
			}
		};
		solve(n - 1, m - 1), solve(n, m - 2), solve(n - 2, m);
		if(n % 2 == 0 || m % 2 == 0) ans.pb(2);
		sort(all(ans)), ans.erase(unique(all(ans)), ans.end());
		cout << sz(ans) << ' ';
		for(auto x : ans) cout << x << ' '; cout << '\n';
	}
	return 0;
}