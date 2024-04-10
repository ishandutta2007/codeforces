#include<bits/stdc++.h>
using namespace std;

int n;
char s[500010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int mn=10000;
	for (int i=1;i<=n;i++)
	{
		mn=min(mn,(int)s[i]);
		if (s[i]==mn) puts("Mike");
		else puts("Ann");
	}
	return 0;
}