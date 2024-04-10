#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i <= b; ++ i)
#define Rof(i, a, b) for (int i = b; i >= a; -- i)
#define yes puts("YES")
#define no puts("NO")
#define line puts("");
typedef long long ll;
using namespace std;
const int N = 1e6 + 5, mod = 998244353;
int T=1,n,m,k,x,y,fl,p,q,num,cnt,c[N];char s[N];
ll r1,r2,r3,d,a[N],ans,sum,f[N],A[N],B[N];
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
inline ll qpow(ll a, ll b) { ll ans = 1; for (; b; b >>= 1, a = a * a % mod) if (b & 1) ans = ans * a % mod; return ans; }
//inline void Get(int *A,int n){For(i,1,n)scanf("%lld",A+i);}
int main() {
	scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	For(i, 1, n) scanf("%lld", a + i), f[i] = 1e18;
	For(i, 1, n) A[i] = a[i] * r1 + r3, B[i] = min(r1 + r2, (a[i] + 2) * r1);
	f[1] = A[1], f[2] = B[1] + B[2] + d * 3;
	for (int i = 2; i <= n; ++ i) {
		f[i] = min(f[i], f[i - 1] + d + min(d * 2 + B[i], A[i]));
		if (i > 2) f[i] = min(f[i], f[i - 2] + d * 4 + B[i - 1] + B[i]);
	}
	ans = f[n], sum = A[n];
	for (int i = n - 2; i >= 0; -- i) ans = min(ans, f[i + 1] + sum + d * (n + n - i - i - 3)), sum += B[i + 1];
	return printf("%lld\n", min(ans, sum + d * 2 * (n - 1))), 0;
}