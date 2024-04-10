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
typedef unsigned long long ull;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1000;
const ull base = 123;
int T, n, m;
char s[maxn + 5], t[maxn + 5];
ull hs[maxn + 5], ht[maxn + 5], sh[maxn + 5], fpw[maxn + 5];
ull get(ull *h, int l, int r) {
	return h[r] - h[l - 1] * fpw[r - l + 1];
}
int main() {
//	freopen("in.txt", "r", stdin);
	fpw[0] = 1;
	rep(i, 1, maxn) fpw[i] = fpw[i - 1] * base;
	for(cin >> T; T; T--) {
		cin >> s + 1 >> t + 1; 
		int flag = 1;
		n = strlen(s + 1), m = strlen(t + 1);
		hs[0] = ht[0] = sh[0] = 1;
		rep(i, 1, n) hs[i] = base * hs[i - 1] + s[i];
		rep(i, 1, m) ht[i] = base * ht[i - 1] + t[i];
		rep(i, 1, n) sh[i] = base * sh[i - 1] + s[n - i + 1]; 
		rep(i, 1, n) {
			rep(j, 1, m) {
				if(i - j + 1 >= 1 && i - m + j <= n && i - m + j >= 1 && get(ht, 1, j) == get(hs, i - j + 1, i) && get(sh,n - i + 1, n - i + m - j + 1) == get(ht, j, m)) {
					flag = 0;
					puts("YES");
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) puts("NO");
	}
	return 0;
}