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
const int maxn = 50;
int T, n;
char s[maxn + 5], ans[maxn + 5][maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		vector<int> v;
		cin >> n >> s + 1;
		rep(i, 1, n + 1) rep(j, 1, n + 1) ans[i][j] = '\0';
		rep(i, 1, n) ans[i][i] = 'X';
		rep(i, 1, n) {
			if(s[i] == '1') {
				rep(j, 1, n) if(i != j) ans[i][j] = ans[j][i] = '=';
			}
			else v.push_back(i);
		}
		if(sz(v) == 1 || sz(v) == 2) {
			puts("NO");
			continue;
		}
		puts("YES");
		rep(i, 0, sz(v) - 1) {
			ans[v[i]][v[(i + 1) % sz(v)]] = '+';
			ans[v[(i + 1) % sz(v)]][v[i]] = '-';
		}
		rep(i, 1, n) rep(j, 1, n) if(ans[i][j] == '\0') ans[i][j] = '=';
		rep(i, 1, n) puts(ans[i] + 1);
	}
	return 0;
}