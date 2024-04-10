/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5;
int T, n;
char s[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> s + 1;
		n = strlen(s + 1);
		int ans = 0;
		rep(i, 1, n) ans += s[i] == '0' && s[i - 1] != '0';
		cout << min(ans, 2) << '\n';
	}
	return 0;
}