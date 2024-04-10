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
const int maxn = 1e5;
int n, q, cnt;
char s[maxn + 5];
inline int count(int i) {
	if(i < 1) return 0;
	return s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), q = read();
	cin >> s + 1;
	rep(i, 1, n) cnt += count(i);
	rep(i, 1, q) {
		int pos = read();
		static char c[5];
		cin >> c;
		cnt -= count(pos - 2), cnt -= count(pos - 1), cnt -= count(pos);
		s[pos] = c[0];
		cnt += count(pos - 2), cnt += count(pos - 1), cnt += count(pos);
		cout << cnt << '\n';
	}
	return 0;
}