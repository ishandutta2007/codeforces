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
const int maxn = 50;
int T, n, m, R[2], W[2];
char s[maxn + 5][maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		W[0] = W[1] = R[0] = R[1] = 0;
		rep(i, 1, n) scanf("%s", s[i] + 1);
		rep(i, 1, n) rep(j, 1, m) 
			if(s[i][j] == 'W') W[i + j & 1] = 1;
			else if(s[i][j] == 'R') R[i + j & 1] = 1;
		if(W[0] && R[0] || W[1] && R[1] || W[0] && W[1] || R[0] && R[1]) puts("NO");
		else {
			puts("YES");
			char t[2] = {W[0] ? 'W' : 'R', W[0] ? 'R' : 'W'};
			if(!W[0] && !W[1]) t[0] = (R[0] ? 'R' : 'W'), t[1] = (R[0] ? 'W' : 'R');
			rep(i, 1, n) {
				rep(j, 1, m) putchar(t[i + j & 1]);
				puts("");
			}
		}
	}
	return 0;
}