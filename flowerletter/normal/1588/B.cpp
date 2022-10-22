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
int T, n, i, j, k;
inline ll ask(int l, int r) {
	cout << "? " << l << ' ' << r << endl;
	ll x; cin >> x;
	return x;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) { 
		cin >> n;
		ll all = ask(1, n);
		int l = 1, r = n, ans = -1;
		while(l <= r) {
			int mid = l + r >> 1;
			if(ask(1, mid) != all) ans = mid, l = mid + 1;
			else r = mid - 1; 
		}	
		int delta = all - ask(1, ans);
		k = ans + 1;
		j = ans - delta + 1;
		i = j - (ask(1, j - 1) - ask(1, j - 2)) - 1;
		cout << "! " << i << ' ' << j << ' ' << k << endl; 
	}
	return 0;
}