#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int ch[9000010][2];
int f[3010][3010],s[3010],n,tot,ans;

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

inline bool check(int x,int y)
{
	if (y-x+1<=3) return true;
	if (y-x+1>4) return false;
	if (!s[x]&&!s[x+1]&&s[x+2]&&s[x+3]) return false;
	if (!s[x]&&s[x+1]&&!s[x+2]&&s[x+3]) return false;
	if (s[x]&&s[x+1]&&s[x+2]&&!s[x+3]) return false;
	if (s[x]&&s[x+1]&&s[x+2]&&s[x+3]) return false;
	return true;
}

inline void insert(int x)
{
	for (int i=x;i;i--) for (int j=x;j>=max(i,x-3);j--) if (check(j,x)) f[i][x]=pls(f[i][x],f[i][j-1]);
	int now=1;
	bool flag=false;
	for (int i=x;i;i--)
	{
		if (!ch[now][s[i]]) ch[now][s[i]]=++tot,flag=true;
		now=ch[now][s[i]];
		if (flag) ans=pls(ans,f[i][x]);
	}
}

int main()
{
	n=rd();tot=1;
	for (int i=1;i<=n;i++) s[i]=rd();
	ans=0;
	for (int i=1;i<=n;i++) f[i][i-1]=1;
	for (int i=1;i<=n;i++) insert(i),print(ans);
	return 0;
}