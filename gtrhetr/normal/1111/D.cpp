#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod=1000000007;

int fac[100010],ifac[100010];
int f[50010],g[52][50010],ans[52][52];
int h[50010],c[52][100010],ic[52][100010];
int cnt[233],n,m;
char s[100010];

char buf[1000010],buff[1000010],*cur=buf+1000010,*curr=buff;

inline char getc()
{
	(cur==buf+1000010)?fread(cur=buf,1,1000010,stdin):0;
	return *cur++;
}

inline int rd()
{
	int x=0;char ch=getc();
	for (;ch<'0'||ch>'9';ch=getc());
	for (;ch>='0'&&ch<='9';ch=getc()) x=x*10+ch-'0';
	return x;
}

inline void flush() { fwrite(buff,1,curr-buff,stdout); }

inline void putc(const char ch)
{
	(curr==buff+1000010)?fwrite(curr=buff,1,1000010,stdout):0;
	*curr++=ch;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putc('0');putc('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putc(s[tot]);
	putc('\n');
}

inline int calc(char ch)
{
	if (ch>='a'&&ch<='z') return ch-'a';
	if (ch>='A'&&ch<='Z') return ch-'A'+26;
	return -1;
}

inline void pls(int &x,int y) { x+=y;(x>=mod)?x-=mod:0; }
inline void mns(int &x,int y) { x-=y;(x<0)?x+=mod:0; }
inline int ksm(int x,int y) { int res=1;for (;y;y>>=1,x=(ll)x*x%mod) if (y&1) res=(ll)res*x%mod;return res; }

inline int C(const int &x,const int &y) { return (x<0||y<0||x<y)?0:(ll)fac[x]*ifac[y]%mod*ifac[x-y]%mod; }
inline int iC(const int &x,const int &y) { return (x<0||y<0||x<y)?0:(ll)ifac[x]*fac[y]%mod*fac[x-y]%mod; }

inline void pre_gao()
{
	fac[0]=1;
	for (int i=1;i<=100000;i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[100000]=ksm(fac[100000],mod-2);
	for (int i=99999;~i;i--) ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
}

int main()
{
	char ch=getc();
	for (;calc(ch)==-1;ch=getc());
	for (n=0;calc(ch)!=-1;ch=getc()) s[++n]=ch;
	m=rd();
	pre_gao();
	for (int i=1;i<=n;i++) cnt[calc(s[i])]++;
	bool flag=true;
	for (int i=0;i<52;i++) if (cnt[i]>n/2) flag=false;
	if (!flag)
	{
		for (int i=1;i<=m;i++) print(0);
		return 0;
	}
	f[0]=1;
	int tot=0;
	for (int i=0;i<=100000;i++) for (int j=0;j<52;j++) c[j][i]=C(i,cnt[j]),ic[j][i]=iC(i,cnt[j]);
	for (int i=0;i<52;i++)
	{
		if (!cnt[i]) continue;
		tot+=cnt[i];
		int hh=min(tot,n/2);
		for (int j=hh;~j;j--)
		{
			if (j>=cnt[i]) f[j]=(ll)((ll)f[j-cnt[i]]*c[i][j]%mod+(ll)f[j]*c[i][tot-j]%mod)%mod;
			else f[j]=(ll)f[j]*c[i][tot-j]%mod;
		}
	}
	for (int hh=0;hh<52;hh++) if (cnt[hh])
	{
		memcpy(g[hh],f,sizeof(g[hh]));
		for (int j=0;j<=n/2-cnt[hh];j++)
		{
			g[hh][j]=(ll)g[hh][j]*ic[hh][n-j]%mod;
			if (j+cnt[hh]<=n/2-cnt[hh]) mns(g[hh][j+cnt[hh]],(ll)g[hh][j]*c[hh][j+cnt[hh]]%mod);
		}
	}
	for (int h1=0;h1<52;h1++) if (cnt[h1]) for (int h2=h1+1;h2<52;h2++) if (cnt[h2])
	{
		if (cnt[h1]+cnt[h2]>n/2) continue;
		memcpy(h,g[h1],sizeof(h));
		for (int j=0;j<=n/2-cnt[h1]-cnt[h2];j++)
		{
			h[j]=(ll)h[j]*ic[h2][n-cnt[h1]-j]%mod;
			if (j+cnt[h2]<=n/2-cnt[h1]-cnt[h2]) mns(h[j+cnt[h2]],(ll)h[j]*c[h2][j+cnt[h2]]%mod);
		}
		ans[h1][h2]=(ll)h[n/2-cnt[h1]-cnt[h2]]*C(n/2,cnt[h1]+cnt[h2])%mod*C(cnt[h1]+cnt[h2],cnt[h1])%mod*2%mod;
	}
	while (m--)
	{
		int x=rd(),y=rd();
		if (calc(s[x])==calc(s[y])) print(f[n/2]);
		else
		{
			int h1=calc(s[x]),h2=calc(s[y]);
			if (h1>h2) swap(h1,h2);
			print(ans[h1][h2]);
		}
	}
	flush();
	return 0;
}