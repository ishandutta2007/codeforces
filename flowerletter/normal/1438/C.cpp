/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 100;
int T, n, m, a[maxn + 5][maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]);
		rep(i, 1, n) rep(j, 1, m) printf("%d%c", a[i][j] + ((i + j & 1) ^ (a[i][j] & 1)), " \n"[j == m]);
	}
	return 0;
}