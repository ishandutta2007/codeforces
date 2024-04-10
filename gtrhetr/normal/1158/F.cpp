#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353

const ll inf=(ll)mod*mod*7;

ll g[3010][3010];
int bin[3010],ibin[3010];
int f[2][3010][2048],h[3010][3010];
int num[3010],ans[3010],cnt[3010],sum[3010][3010],n,m,c;

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline int pls(const int &x,const int &y) { return (x+y<mod)?x+y:x+y-mod; }
inline int mns(const int &x,const int &y) { return (x-y<0)?x-y+mod:x-y; }
inline int ksm(int x,int y) { int res=1;for (;y;y>>=1,x=(ll)x*x%mod) if (y&1) res=(ll)res*x%mod;return res; }

const int inv2=ksm(2,mod-2);

inline void pre_gao()
{
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=pls(bin[i-1],bin[i-1]);
	for (int i=0;i<=n;i++) ibin[i]=ksm(mns(bin[i],1),mod-2);
}

inline void gao1()
{
	int cur=0;
	f[cur][0][0]=1;
	for (int i=1;i<=n;i++)
	{
		cur^=1;
		for (int j=0;j<=i/c;j++) for (int k=0;k<(1<<c);k++) f[cur][j][k]=f[cur^1][j][k];
		for (int j=0;j<=i/c;j++) for (int k=0;k<(1<<c);k++) if (f[cur^1][j][k])
		{
			int hh=k|(1<<(num[i]-1));
			if (hh==(1<<c)-1) f[cur][j+1][0]=pls(f[cur][j+1][0],f[cur^1][j][k]);
			else f[cur][j][hh]=pls(f[cur][j][hh],f[cur^1][j][k]);
		}
	}
	for (int i=0;i<=m;i++) for (int j=0;j<(1<<c);j++) ans[i]=pls(ans[i],f[cur][i][j]);
	ans[0]=mns(ans[0],1);
	for (int i=0;i<=n;i++) print(ans[i]);
	putchar('\n');
}

inline void gao2()
{
	for (int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof(cnt));
		int c0=c,now=1;
		for (int j=i;j<=n;j++)
		{
			if (cnt[num[j]]==0) c0--;
			else now=(ll)now*ibin[cnt[num[j]]]%mod;
			h[i][j]=(c0)?0:now;
			cnt[num[j]]++;
			now=(ll)now*mns(bin[cnt[num[j]]],1)%mod;
		}
	}
	for (int i=n;i;i--)
	{
		memcpy(sum[i],sum[i+1],sizeof(sum[i]));
		sum[i][num[i]]++;
	}
	g[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int k=0;k<i;k++) for (int j=0;j<=k/c;j++)
		{
			g[i][j+1]+=g[k][j]*h[k+1][i];
			(g[i][j+1]>=inf)?g[i][j+1]-=inf:0;
		}
		for (int j=0;j<=i/c;j++) g[i][j]%=mod;
	}
	for (int i=0;i<=n;i++)
	{
		int hh=bin[n-i],now=1;
		for (int j=1;j<=c;j++) now=(ll)now*mns(bin[sum[i+1][j]],1)%mod;
		hh=mns(hh,now);
		for (int j=0;j<=m;j++) ans[j]=pls(ans[j],(ll)g[i][j]*hh%mod);
	}
	ans[0]=mns(ans[0],1);
	for (int i=0;i<=n;i++) print(ans[i]);
	putchar('\n');
}

int main()
{
	n=rd();c=rd();pre_gao();
	for (int i=1;i<=n;i++) num[i]=rd();
	if (n<c) { print(mns(bin[n],1));for (int i=1;i<=n;i++) print(0);putchar('\n');return 0; }
	m=n/c;
	if (c<=11) gao1();
	else gao2();
	return 0;
}