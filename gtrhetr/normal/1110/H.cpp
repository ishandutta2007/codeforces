#include<bits/stdc++.h>
using namespace std;

queue<int> q;

int f[2010][20010],g[20010][2010];
int ch[20010][10],fail[20010],n,tot;
bool bo[2010][20010];
char l[810],r[810];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int max(const int &x,const int &y) { return (x>y)?x:y; }

inline int trans(const int &x,const int &y) { return (!ch[x][y])?(ch[x][y]=++tot):ch[x][y]; }

inline void pre_gao()
{
	int len1=strlen(l+1),len2=strlen(r+1);
	for (int i=1;i<=len1;i++) l[i]-='0';
	for (int i=1;i<=len2;i++) r[i]-='0';
	tot=0;
	if (len1==len2)
	{
		int h1=0,h2=0;
		for (int i=1;i<=len1;i++)
		{
			if (h1==h2) for (int j=l[i]+1;j<r[i];j++) g[trans(h1,j)][len1-i]++;
			else
			{
				for (int j=l[i]+1;j<10;j++) g[trans(h1,j)][len1-i]++;
				for (int j=0;j<r[i];j++) g[trans(h2,j)][len2-i]++;
			}
			h1=trans(h1,l[i]);h2=trans(h2,r[i]);
		}
		g[h1][0]++;
		if (h1!=h2) g[h2][0]++;
	}
	else
	{
		int h1=0,h2=0;
		for (int i=1;i<=len1;i++)
		{
			for (int j=l[i]+1;j<10;j++) g[trans(h1,j)][len1-i]++;
			h1=trans(h1,l[i]);
		}
		for (int i=1;i<=len2;i++)
		{
			for (int j=0;j<r[i];j++) g[trans(h2,j)][len2-i]++;
			h2=trans(h2,r[i]);
		}
		g[h1][0]++;g[h2][0]++;
		for (int i=len1+1;i<len2;i++) for (int j=1;j<10;j++) g[trans(0,j)][i-1]++;
	}
	ch[0][0]=0;
}

inline void get_fail()
{
	for (int i=0;i<10;i++) if (ch[0][i]) q.push(ch[0][i]);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<=n;i++) g[x][i]+=g[fail[x]][i];
		for (int i=0;i<10;i++)
		{
			if (ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
}

int main()
{
	scanf("%s%s",l+1,r+1);n=rd();
	pre_gao();get_fail();
	for (int i=0;i<=tot;i++) for (int j=1;j<n;j++) g[i][j]+=g[i][j-1];
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for (int i=0;i<n;i++) for (int j=0;j<=tot;j++) if (~f[i][j]) for (int k=0;k<10;k++)
	{
		int hh=ch[j][k];
		f[i+1][hh]=max(f[i+1][hh],f[i][j]+g[hh][n-i-1]);
	}
	int ans=0;
	for (int i=0;i<=tot;i++) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	for (int i=0;i<=tot;i++) if (f[n][i]==ans) bo[n][i]=true;
	for (int i=n-1;~i;i--) for (int j=0;j<=tot;j++) if (~f[i][j]) for (int k=0;k<10;k++)
	{
		int hh=ch[j][k];
		if (f[i+1][hh]==f[i][j]+g[hh][n-i-1]&&bo[i+1][hh]) bo[i][j]=true;
	}
	int now=0;
	for (int i=1;i<=n;i++)
	{
		int id=-1;
		for (int j=0;j<10;j++) if (f[i][ch[now][j]]==f[i-1][now]+g[ch[now][j]][n-i]&&bo[i][ch[now][j]]) { id=j;break; }
		putchar(id+'0');now=ch[now][id];
	}
	putchar('\n');
	return 0;
}