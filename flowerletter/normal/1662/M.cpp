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
	for(cin>> T; T; T--) {
		int n, m;
		cin >> n >> m;
		vector<array<int, 2>> a(m);
		vector<int> mx(2);
		rep(i, 0, m - 1) rep(j, 0, 1) cin >> a[i][j], chkmx(mx[j], a[i][j]);
		if(mx[0] + mx[1] > n) cout << "IMPOSSIBLE\n";
		else {
			rep(i, 1, mx[0]) cout << 'R';
			rep(i, 1, n - mx[0]) cout << 'W';
			cout << '\n';
		}
	}
	return 0;
}