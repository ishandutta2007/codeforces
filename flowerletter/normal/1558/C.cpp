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
const int maxn = 2021;
int T, n, a[maxn + 5], rev[maxn + 5];
vector<int> ans;
void update(int x) {
	ans.push_back(x);
	rep(i, 1, x / 2) swap(a[i], a[x - i + 1]), swap(rev[a[i]], rev[a[x - i + 1]]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		int flag = 1;
		cin >> n;
		rep(i, 1, n) cin >> a[i], flag &= ((i & 1) == (a[i] & 1)), rev[a[i]] = i;
		if(!flag) puts("-1");
		else {
			for(int i = n; i > 1; i -= 2) {
				update(rev[i]);
				update(rev[i - 1] - 1);
				update(rev[i - 1] + 1);
				update(3);
				update(i);
			}
			cout << sz(ans) << '\n';
			for(auto x : ans) cout << x << ' '; puts("");
			ans.clear();
		}
	}
	return 0;
}