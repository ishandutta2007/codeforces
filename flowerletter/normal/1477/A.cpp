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

const int maxn = 2e5 + 10;
int T, n;
ll k, a[maxn + 5];

int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d%lld", &n, &k);
		rep(i, 1, n) scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		ll gcd = 0;
		rep(i, 2, n) gcd = __gcd(gcd, a[i] - a[i - 1]);
		puts((k - a[1]) % gcd == 0 ? "YES" : "NO");
	}
	return 0;
}