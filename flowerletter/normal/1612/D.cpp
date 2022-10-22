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
bool solve(ll a, ll b, ll x) {
	if(a == x || b == x) return 1;
	if(a < x && b < x) return 0;
	if(a < b) swap(a, b);
	if(!b) return 0;
	if(x % b == a % b) return 1;
	return solve(b, a % b, x); 
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		ll a = read(), b = read(), x = read();
		cout << (solve(a, b, x) ? "YES\n" : "NO\n"); 
	}
	return 0;
}