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
int T, n, x, a[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &x);
		rep(i, 1, n) scanf("%d", &a[i]);
		sort(a + 1, a + n +1);
		int sum = 0;
		rep(i, 1, n) sum += a[i];
		if(sum == x) puts("NO");
		else  {
			puts("YES");
			sum = 0;
			int flag = 0;
			rep(i, 1, n - 1) {
				if(sum + a[i] == x) cout << a[n] << ' ', flag = 1, sum += a[n];
				cout << a[i] << ' ', sum += a[i];
			}
			if(!flag) cout << a[n] << ' ';
			puts(""); 
		}
	}
	return 0;
}