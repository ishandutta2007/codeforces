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
int T, n, sum, a[maxn + 5];
bool check(int x) {
	rep(i, 2, sqrt(x)) if(x % i == 0) return 0;
	return 1;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --){
		cin >> n; sum = 0;
		rep(i, 1, n) cin >> a[i], sum += a[i];
		if(!check(sum)) {
			cout << n << '\n';
			rep(i, 1, n) cout << i << " \n"[i == n];
		}
		else {
			int p, mn = 1e9;
			rep(i, 1, n) if((a[i] & 1) && chkmn(mn, a[i])) p = i;
			cout << n - 1 << '\n';
			rep(i, 1, n) if(i != p) cout << i << ' ';
			puts("");
		}
	}
	return 0;
}