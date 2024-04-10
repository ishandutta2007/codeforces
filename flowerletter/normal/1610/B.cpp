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
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 2e5;
int n, a[maxn + 5];
bool del(int x) {
	vector<int> s;
	rep(i, 1, n) if(a[i] != x) s.pb(a[i]);
	rep(i, 0, sz(s) - 1) if(s[i] != s[sz(s) - 1 - i]) return 0;
	return 1; 
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) a[i] = read();
		int l = 1, r = n, flag = 1;
		while(l <= r) {
			if(a[l] != a[r]) {
				cout << ((del(a[l]) || del(a[r])) ? "YES\n" : "NO\n"); 
				flag = 0;
				break;
			}
			l ++ , r --;
		}
		if(flag) {
			cout << "YES\n";
		}
	}
	return 0;
}