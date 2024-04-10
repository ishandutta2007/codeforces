#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i <= b; ++ i)
#define Rof(i, a, b) for (int i = b; i >= a; -- i)
#define yes puts("YES")
#define no puts("NO")
#define line puts("");
typedef long long ll;
using namespace std;
const int N = 3e5 + 5, mod = 998244353;
int T=1,n,m,k,x,y,ans,fl,p,q,num,cnt,c[N],f[N];char s[N];
int a[N],b[N];
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}
inline ll qpow(ll a, ll b) { ll ans = 1; for (; b; b >>= 1, a = a * a % mod) if (b & 1) ans = ans * a % mod; return ans; }
inline void Get(int *A,int n){For(i,1,n)scanf("%lld",A+i);}
int main() {
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);Get(a,n);
		int sum=0,mx=0;
		for(int i=1;i<=n;i++)sum+=a[i],mx=max(mx,a[i]);
		if(mx*2>sum||sum&1)puts("T");else puts("HL");
	}
	return 0;
}