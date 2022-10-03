#include<bits/stdc++.h>
using namespace std;

int n;
char s[5010],t[5010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	bool flag=true;
	for (int i=1;i<=n/2;i++) if (s[i]!=s[1]) flag=false;
	if (flag) { puts("Impossible");return 0; }
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<=n;j++) t[j]=s[(i+j-1)%n+1];
		bool flag=true;
		for (int j=1;j<=n;j++) if (t[j]!=s[j]) flag=false;
		bool flag1=true;
		for (int j=1;j<=n/2;j++) if (t[j]!=t[n-j+1]) flag1=false;
		if (!flag&&flag1) { puts("1");return 0; }
	}
	puts("2");
	return 0;
}