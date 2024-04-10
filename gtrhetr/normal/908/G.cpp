#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int f[710][710][2],g[10][710],bin[710],n;
char s[710];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int pls(const int &x,const int &y) { return (x+y<mod)?x+y:x+y-mod; }
inline int mns(const int &x,const int &y) { return (x-y<0)?x-y+mod:x-y; }
inline int ksm(int x,int y) { int res=1;for (;y;y>>=1,x=(ll)x*x%mod) if (y&1) res=(ll)res*x%mod;return res; }

inline void gao(int now)
{
	memset(f,0,sizeof(f));
	f[n+1][0][1]=1;
	for (int i=n;i;i--) for (int j=0;j<=n-i;j++) for (int k=0;k<2;k++) if (f[i+1][j][k])
	{
		if (!k) for (int l=0;l<10;l++)
		{
			int hh=(l>=now);
			f[i][j+hh][0]=pls(f[i][j+hh][0],f[i+1][j][k]);
		}
		else for (int l=0;l<=s[i]-'0';l++)
		{
			bool flag=(l==s[i]-'0'),hh=(l>=now);
			f[i][j+hh][flag]=pls(f[i][j+hh][flag],f[i+1][j][k]);
		}
	}
	for (int i=0;i<=n;i++) g[now][i]=pls(f[1][i][0],f[1][i][1]);
	for (int i=n-1;~i;i--) g[now][i]=pls(g[now][i],g[now][i+1]);
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	reverse(s+1,s+n+1);
	for (int i=0;i<10;i++) gao(i);
	for (int i=0;i<9;i++) for (int j=0;j<=n;j++) g[i][j]=mns(g[i][j],g[i+1][j]);
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=(ll)bin[i-1]*10%mod;
	int ans=0;
	for (int i=1;i<10;i++) for (int j=1;j<=n;j++) ans=pls(ans,(ll)g[i][j]*i%mod*bin[j-1]%mod);
	printf("%d\n",ans);
	return 0;
}