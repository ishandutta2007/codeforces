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
const int maxn = 1e4;
const int base = 26;
int n;
char s[maxn + 5], t[3][maxn + 5], r[3][maxn + 5], ans[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> s + 1;
	n = strlen(s + 1);
	rep(i, 0, 2) {
		rep(j, 1, n) {
			int x = j;
			rep(k, 0, i - 1) x /= base;
			t[i][j] = x % base + 'a';
		}
		cout << "? " << t[i] + 1 << endl;
		cin >> r[i] + 1;
	}
	rep(i, 1, n) {
		rep(j, 1, n) if(t[0][i] == r[0][j] && t[1][i] == r[1][j] && t[2][i] == r[2][j]) {
			ans[i] = s[j];
		} 
	}
	cout << "! " << ans + 1 << '\n';
	return 0;
}