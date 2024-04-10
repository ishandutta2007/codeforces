/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}

const int maxn = 1e5;
int T, n, k, nxt[maxn + 5];
char s[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d%s", &n, &k, s + 1);
		int ans = 0, st = -1, ed = -1;
		rep(i, 1, n) if(s[i] == '*') {st = i, ans++, s[i] = 'x';break;} 
		per(i, n, 1) if(s[i] == '*') {ed = i, ans++, s[i] = 'x';break;}
		if(st == -1 || ed == -1) {printf("%d\n", ans); continue;}
		per(i, n, 1) if(s[i] == '*') nxt[i] = ed, ed = i;
		rep(i, 1, n) {
			if(s[i] == '*' && nxt[i] - st > k) st = i, ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}