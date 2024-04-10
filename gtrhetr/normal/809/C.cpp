#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define y1 DCXISSOHANDSOME

int f[32][2][2][2],g[32][2][2][2],q;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline int pls(const int &x,const int &y) { return (x+y<mod)?x+y:x+y-mod; }
inline int mns(const int &x,const int &y) { return (x-y<0)?x-y+mod:x-y; }

inline int gao(int x,int y,int z)
{
	if (x<0||y<0) return 0;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[31][1][1][1]=1;
	for (int i=30;~i;i--) for (int j=0;j<2;j++) for (int k=0;k<2;k++) for (int l=0;l<2;l++) if (f[i+1][j][k][l])
	{
		for (int p=0;p<2;p++) for (int q=0;q<2;q++)
		{
			if (j&&!((1<<i)&x)&&p) continue;
			if (k&&!((1<<i)&y)&&q) continue;
			if (l&&!((1<<i)&z)&&(p^q)) continue;
			int j1=(j&&(p==((x>>i)&1))),k1=(k&&(q==((y>>i)&1))),l1=(l&&(p^q)==((z>>i)&1));
			f[i][j1][k1][l1]=pls(f[i][j1][k1][l1],f[i+1][j][k][l]);
			g[i][j1][k1][l1]=pls(g[i][j1][k1][l1],g[i+1][j][k][l]);
			if (p^q) g[i][j1][k1][l1]=pls(g[i][j1][k1][l1],(ll)(1<<i)*f[i+1][j][k][l]%mod);
		}
	}
	int ans=0;
	for (int i=0;i<2;i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) ans=pls(ans,pls(f[0][i][j][k],g[0][i][j][k]));
	return ans;
}

int main()
{
	q=rd();
	while (q--)
	{
		int x1=rd()-1,y1=rd()-1,x2=rd()-1,y2=rd()-1,k=rd()-1;
		print(mns(pls(gao(x2,y2,k),gao(x1-1,y1-1,k)),pls(gao(x1-1,y2,k),gao(x2,y1-1,k))));
	}
	return 0;
}