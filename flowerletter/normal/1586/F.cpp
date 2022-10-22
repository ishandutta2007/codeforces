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
int n, k; 
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> k;
	int res = 1, ans = 0;
	while(res < n) res *= k, ans ++;
	cout << ans << '\n';
	rep(i, 1, n) rep(j, i + 1, n) {
		int res = 1, x = i - 1, y = j - 1;
		vector<int> s, t;
		rep(l, 1, ans) s.push_back(x % k), x /= k;
		rep(l, 1, ans) t.push_back(y % k), y /= k;
		per(l, ans - 1, 0) {
			if(s[l] == t[l]) res ++;
			else break;
		}
		cout << res << ' ';
	}
	return 0;
}