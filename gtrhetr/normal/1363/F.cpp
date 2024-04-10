#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000

int f[2010][2010];
int c1[2010][26],c2[2010][26],t,n;
char s1[2010],s2[2010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{
	n=rd();
	scanf("%s%s",s1+1,s2+1);
	memset(c1[n+1],0,sizeof(c1[n+1]));
	memset(c2[n+1],0,sizeof(c2[n+1]));
	for (int i=n;i;i--)
	{
		memcpy(c1[i],c1[i+1],sizeof(c1[i]));
		memcpy(c2[i],c2[i+1],sizeof(c2[i]));
		c1[i][s1[i]-'a']++;c2[i][s2[i]-'a']++;
	}
	for (int i=1;i<=n+1;i++) for (int j=1;j<=n+1;j++) f[i][j]=inf;
	for (int i=1;i<=n+1;i++) f[i][n+1]=0;
	for (int i=n;i;i--) for (int j=n;j;j--)
	{
		f[i][j]=min(f[i][j],f[i+1][j]);
		if (s1[i]==s2[j]) f[i][j]=min(f[i][j],f[i+1][j+1]);
		if (c1[i][s2[j]-'a']-c2[j+1][s2[j]-'a']>0) f[i][j]=min(f[i][j],f[i][j+1]+1);
	}
	if (f[1][1]==inf) puts("-1");
	else printf("%d\n",f[1][1]);
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}