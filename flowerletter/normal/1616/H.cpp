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
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 1.5e5;
const int lg = 30;
const int mod = 998244353;
int n, x, a[maxn + 5]; 
int lim, fpw[maxn + 5];
map<int, vector<int>> mp;
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
int get(vector<int> L, vector<int> R, int dep) {
	if(L.empty() && R.empty()) return 1; 
	if(dep == -1) {
		return fpw[sz(L) + sz(R)];
	}
	vector<int> p[2], q[2];
	for(auto x : L) p[x >> dep & 1].pb(x);
	for(auto x : R) q[x >> dep & 1].pb(x);
	
	if(x >> dep & 1) {
		return mul(get(p[0], q[1], dep - 1), get(q[0], p[1], dep - 1));
	} 
	else {
		return add(add(add(get(p[0], q[0], dep - 1), get(p[1], q[1], dep - 1)), 1), 
			   add(sub(fpw[sz(L)], add(fpw[sz(p[0])], fpw[sz(p[1])])), 
			       sub(fpw[sz(R)], add(fpw[sz(q[0])], fpw[sz(q[1])]))));
	} 
}
int solve(vector<int> s) {
	vector<int> p, q;
	for(auto x : s) if(x >> lim & 1) q.pb(x); else p.pb(x);
	return get(p, q, lim - 1);
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), x = read();
	fpw[0] = 1;
	rep(i, 1, n) a[i] = read(), fpw[i] = mul(fpw[i - 1], 2);
	lim = -1;
	per(i, lg, 0) if(x >> i & 1) {lim = i; break;}
	vector<int> st;
	rep(i, 1, n) {
		st.pb(a[i] >> lim + 1);
	}
	vector<vector<int>> S;
	sort(all(st)), st.erase(unique(all(st)), st.end());
	S.resize(sz(st));
	rep(i, 1, n) {
		S[lower_bound(all(st), a[i] >> lim + 1) - st.begin()].pb(a[i]);
	}
	int ans = 0;
	if(!x) {
		for(auto x : S) ans = add(ans, fpw[sz(x)] - 1);
		cout << ans << '\n';
		return 0; 
	}
	for(auto x : S) ans = add(ans, sub(solve(x), 1));
	cout << ans << '\n';
	return 0;
}