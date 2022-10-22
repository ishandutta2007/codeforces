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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5;
int T, n;
char s[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%s", &n, s + 1);
		int res = 0;
		rep(i, 1, n / 2) if(s[i] != s[n - i + 1]) res ++, s[i] = s[n - i + 1] = '1';
		int cnt0 = 0;
		rep(i, 1, n) cnt0 += (s[i] == '0');
		if(cnt0 == 0) puts(res ? "ALICE" : "DRAW");
		else if(cnt0 == 1) {
			if(res == 0) puts("BOB");
			else if(res == 1) puts("DRAW");
			else puts("ALICE");
		}
		else if((n & 1) && (s[(n + 1) / 2] == '0')) {
			if(res == 0) puts("ALICE");
			else if(res == 1) puts("ALICE");
			else puts("ALICE");
		}
		else {
			if(res == 0) puts("BOB");
			else if(res == 1) puts("ALICE");
			else if(res == 2) puts("ALICE");
			else puts("ALICE");
		}
	}
	return 0;
}