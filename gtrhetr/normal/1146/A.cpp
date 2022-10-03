#include<bits/stdc++.h>
using namespace std;

int n;
char s[510];

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
	int hh=0;
	for (int i=1;i<=n;i++) hh+=(s[i]=='a');
	printf("%d\n",min(hh*2-1,n));
	return 0;
}