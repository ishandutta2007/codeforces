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
int n, k, gcd, a[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &k), gcd = k;
	rep(i, 1, n) scanf("%d", &a[i]), gcd = __gcd(gcd, a[i] % k);
	printf("%d\n", (k - 1) / gcd + 1);
	rep(i, 0, (k - 1) / gcd) printf("%d ", i * gcd); 
	return 0;
}