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
const int maxn = 1e6;
int T, n, u, v, a[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d%d", &n, &u, &v);
		int flag = 1;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 2, n) flag &= (abs(a[i] - a[i - 1]) <= 1);
		if(!flag) puts("0");
		else {
			int ans = 2e9;
			rep(i, 2, n) if(a[i - 1] == a[i]) chkmn(ans, v + v), chkmn(ans, u + v);
			rep(i, 2, n) if(a[i - 1] == a[i] - 1 || a[i - 1] == a[i] + 1) chkmn(ans, v), chkmn(ans, u);
			cout << ans << endl;
		}
	}
	return 0;
}