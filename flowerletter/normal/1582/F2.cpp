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
const int maxn = 1e6;
const int maxm = 1 << 13;
const int inf = 1e9;
int n, a[maxn + 5], f[maxm + 5];
vector<int> p[maxm + 5], ans;
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i, 1, n) cin >> a[i], p[a[i]].push_back(i);
	f[0] = 0;
	rep(i, 1, maxm) f[i] = inf;
	rep(i, 1, maxm) if(!p[i].empty()){
		rep(j, 0, maxm) if(f[j] < p[i].back()) {
			chkmn(f[j ^ i], *lower_bound(all(p[i]), f[j]));
		}
	}
	rep(i, 0, maxm) if(f[i] != inf) ans.push_back(i);
	cout << sz(ans) << '\n';
	for(auto x : ans) cout << x << ' ' ;
	return 0;
}