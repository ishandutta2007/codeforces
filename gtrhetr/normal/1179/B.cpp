#include<bits/stdc++.h>
using namespace std;

int n,m;

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

inline void print(int x,int y)
{
	print(x);print(y);
	putchar('\n');
}

inline void gao(int n,int m,int k)
{
	if (!n||!m) return;
	if (n==1)
	{
		int h1=1,h2=m;
		for (int i=1;i<=m;i++)
		{
			if (i&1) print(1+k,h1+k),h1++;
			else print(1+k,h2+k),h2--;
		}
		return;
	}
	if (m==1)
	{
		int h1=1,h2=n;
		for (int i=1;i<=n;i++)
		{
			if (i&1) print(h1+k,1+k),h1++;
			else print(h2+k,1+k),h2--;
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
		print(i+k,1+k);
		print((n-i+1)+k,m+k);
	}
	if (m>2)
	{
		for (int i=2;i<m;i++)
		{
			print(1+k,i+k);
			print(n+k,(m-i+1)+k);
		}
	}
	gao(n-2,m-2,k+1);
}

int main()
{
	n=rd();m=rd();
	gao(n,m,0);
	return 0;
}