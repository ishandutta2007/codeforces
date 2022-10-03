#include<bits/stdc++.h>
using namespace std;

int n,b,g;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	b=rd();g=rd();n=rd();
	int l=max(0,n-g),r=min(n,b);
	printf("%d\n",r-l+1);
	return 0;
}