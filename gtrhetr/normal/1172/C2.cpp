#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353LL

ll inv[10010],f[3010][3010],g[3010][3010];
int a[200010],w[200010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline ll Inv(const int &x) { return inv[x+m]; }

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<=n;i++) w[i]=rd();
	int sum1=0,sum2=0;
	for (int i=1;i<=n;i++) if (a[i]) sum1+=w[i];else sum2+=w[i];
	for (int i=0;i<=m*2;i++) inv[i]=ksm(pls(sum1+sum2,mns(i,m)),mod-2);
	for (int i=m;~i;i--) for (int j=m-i;~j;j--)
	{
		if (i+j==m) { f[i][j]=g[i][j]=1;continue; }
		if (j>sum2) continue;
		f[i][j]=pls((ll)(sum1+i+1)*Inv(i-j)%mod*f[i+1][j]%mod,(ll)(sum2-j)*Inv(i-j)%mod*f[i][j+1]%mod);
		g[i][j]=pls((ll)(sum1+i)*Inv(i-j)%mod*g[i+1][j]%mod,(ll)(sum2-j-1)*Inv(i-j)%mod*g[i][j+1]%mod);
	}
	for (int i=1;i<=n;i++) if (a[i]) print(f[0][0]*w[i]%mod);else print(g[0][0]*w[i]%mod);
	return 0;
}