#include<bits/stdc++.h>
using namespace std;

int b,k;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	b=rd();k=rd();
	if (!(b&1))
	{
		int x;
		for (int i=1;i<=k;i++) x=rd();
		if (x&1) puts("odd");
		else puts("even");
		return 0;
	}
	int ans=0;
	for (int i=1;i<=k;i++) ans=(ans+rd())&1;
	if (ans&1) puts("odd");
	else puts("even");
	return 0;
}