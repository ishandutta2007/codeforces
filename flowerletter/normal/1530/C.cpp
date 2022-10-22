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
const int maxn = 1e5;
int T, n, a[maxn + 5], b[maxn + 5];
ll val(vector<int> s) {
	sort(all(s)), reverse(all(s));
	ll sum = 0;
	int lim = sz(s) - sz(s) / 4 - 1;
	rep(i, 0, lim) sum += s[i];
	return sum;
}
bool check(int x) {
	vector<int> s1(a + 1, a + n + 1), s2(b + 1, b + n + 1);
	rep(i, 1, x) s1.push_back(100);
	rep(i, 1, x) s2.push_back(0);
	return val(s1) >= val(s2);
}
int main() {
//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T--) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		rep(i, 1, n) cin >> b[i];
		int l = 0, r = n, ans = -1;
		while(l <= r) {
			int mid = l + r >> 1;
			if(check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}