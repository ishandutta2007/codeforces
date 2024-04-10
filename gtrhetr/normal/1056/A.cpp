#include<bits/stdc++.h>
using namespace std;

int num[110],n;

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++)
	{
		int k=rd();
		for (int j=1;j<=k;j++) num[rd()]++;
	}
	for (int i=1;i<=100;i++) if (num[i]==n) print(i);
	putchar('\n');
	return 0;
}