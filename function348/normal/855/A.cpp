#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n;
char s[1000][1000];
int len[1000];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
		int f=0;
		for (int j=1;j<i;j++)
		if (len[j]==len[i])
		{
			int ok=1;
			for (int k=0;k<len[i];k++)
			if (s[i][k]!=s[j][k]) ok=0;
			if (ok) f=1;
		}
		printf(f?"YES\n":"NO\n");
	}
	return 0;
}