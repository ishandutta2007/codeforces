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
const int maxn = 100; 
int n, ans[maxn + 5];
int ask(int x, int y) {
	cout << "? ";
	rep(i, 1, n - 1) cout << x << ' ';
	cout << y << endl;
	int t; cin >> t; return t;
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i, 1, n - 1) ans[ask(n, i)] = - n + i;
	rep(i, 2, n) ans[ask(1, i)] = i - 1;
	ans[n] = 0;
	int mn = *min_element(ans + 1, ans + n + 1);
	cout << "! ";
	rep(i, 1, n) cout << ans[i] - mn + 1 << ' ';
	cout << endl;
	rep(i, 1, n)
	return 0;
}