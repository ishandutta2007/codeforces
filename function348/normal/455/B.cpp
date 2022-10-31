#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int n,k,num;
int f[N],g[N];
int ch[N][26];
char s[N];
int main()
{
	scanf("%d%d",&n,&k);
	num=1;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int m=strlen(s),now=1;
		for (int j=0;j<m;j++)
		{
			if (!ch[now][s[j]-'a']) ch[now][s[j]-'a']=++num;
			now=ch[now][s[j]-'a'];
		}
	}
	for (int i=num;i>=1;i--)
	{
		f[i]=0;
		for (int j=0;j<26;j++)
		if (ch[i][j]&&!f[ch[i][j]]) { f[i]=1;break;}
	}
	for (int i=num;i>=1;i--)
	{
		int flag=1;
		for (int j=0;j<26;j++)
		if (ch[i][j])
		{
			if (!g[ch[i][j]]) { g[i]=1;break;}
			flag=0;
		}
		if (flag) g[i]=1;
	}
	if (f[1]&&g[1]) printf("First\n");else
	if (!f[1]&&!g[1]) printf("Second\n");else
	if (f[1]&&!g[1]) printf((k&1)?"First\n":"Second\n");else
	if (!f[1]&&g[1]) printf("Second\n");
	return 0;
}