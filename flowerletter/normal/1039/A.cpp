#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 2e5;
const ll inf = 3e18;
int n, x[maxn + 5], l[maxn + 5], r[maxn + 5], lim[maxn + 5], cnt[maxn + 5];
ll t, a[maxn + 5], b[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), t = read();
	rep(i, 1, n) a[i] = read() + t, r[i] = n, l[i] = 1, b[i] = inf;
	rep(i, 1, n) {
		x[i] = read();
		if(x[i] < x[i - 1]) {cout << "No\n"; return 0;}
		l[x[i] + 1] = x[i] + 1;
		r[x[i]] = x[i];
	}
	rep(i, 1, n) chkmx(l[i], l[i - 1]);
	per(i, n - 1, 1) chkmn(r[i], r[i + 1]);
	rep(i, 1, n) {
		if(l[i] > x[i]) {
			cout << "No\n"; 
			return 0;;
		}
		chkmn(r[i], x[i]);
	}
	rep(i, 1, n) chkmn(b[l[i] - 1], a[i] - 1);
	per(i, n - 1, 1) chkmn(b[i], b[i + 1] - 1);
	rep(i, 1, n) if((lim[i] = lower_bound(b + 1, b + n + 1, a[i]) - b) < l[i]) {
		cout << "No\n"; 
		return 0;;
	}
	vector<int> p;
	rep(i, 1, n) if(i - (lower_bound(lim + 1, lim + n + 1, i) - lim) == 0) {
		p.pb(i);
	}
	p.pb(n + 1);
	rep(i, 1, n) if(lim[i] != x[i] && *lower_bound(all(p), lim[i] + 1) != x[i] + 1) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	rep(i, 1, n) cout << b[i] << ' ';
	return 0;
}