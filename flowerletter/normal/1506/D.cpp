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
const int maxn = 2e5;
int T, n, a[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		int p = -1, nw = 0;
		rep(i, 1, n) {
			if(p != a[i]) nw--;
			else nw++;
			if(nw < 0) nw = 1, p = a[i];
		}
		nw = 0;
		rep(i, 1, n) if(a[i] == p) nw++;
		if(nw <= n / 2) printf("%d\n", n & 1);
		else printf("%d\n", nw - (n - nw));
	}
	return 0;
}