#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		int n = read(), k = read();
		if(k == n - 1) {
			if(n == 4) cout << -1 << '\n';
			else {
				cout << n - 1 << ' ' << n / 2 - 1 << '\n';
				cout << n / 2 << ' ' << n / 2 + 1 << '\n';
				rep(i, 1, n / 2 - 3) {
					cout << i << ' ' << n - 1 - i << '\n'; 
				}
				cout << 0 << ' ' << n / 2 - 2 << '\n';
			}
			continue;
		}
		cout << k << ' ' << n - 1 << '\n';
		rep(i, 1, n / 2 - 1) {
			if(i == k || n - 1 - i == k) cout << 0 << ' ' << n - 1 - k << '\n';
			else cout << i << ' ' << n - 1 - i << '\n';
		}
	}
	return 0;
}