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
const int maxn = 1e9;
int x; 
ll chk(ll x) {
	ll t = sqrt(x);
	while(t * t < x) t ++ ;
	return t * t == x ? t : 0;
}
bool solve(ll n, ll t) {
	if(!t) return 0;
	ll m = n / t; 
	while(n / m < t) m --;
	while(n / m > t) m ++;
	if(n / m == t && n <= 1e9 && m <= 1e9) {
		cout << n << ' ' << m << '\n';
		return 1;
	}
	return 0;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		x = read();
		if(!x) {cout << "1 1\n"; continue;}
		int flg = 1;
		rep(i, 1, sqrt(x)) if(x % i == 0) {
			if((i + x / i) % 2 == 0 && solve((i + x / i) / 2, (x / i - i) / 2)) {flg = 0; break;}
		}
		if(flg) cout << -1 << '\n';
	}
	return 0;
}