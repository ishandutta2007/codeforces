#include<bits/stdc++.h>
using namespace std;

int n,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();k=rd();
	int hh=(n-k)/2;
	for (int i=1;i<=n;i++) if (i%(hh+1)==0) putchar('0');else putchar('1');
	putchar('\n');
	return 0;
}