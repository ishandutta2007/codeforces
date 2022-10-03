#include<bits/stdc++.h>
using namespace std;

int n;
char s[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	scanf("%s",s+1);
	int s1=0,s2=0;
	for (int i=1;i<=n;i++) if (s[i]=='z') s1++;else if (s[i]=='n') s2++;
	for (int i=1;i<=s2;i++) printf("1 ");
	for (int i=1;i<=s1;i++) printf("0 ");
	return 0;
}