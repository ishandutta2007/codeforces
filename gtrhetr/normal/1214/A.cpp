#include<bits/stdc++.h>
using namespace std;

int n,d,e;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();d=rd();e=rd()*5;
	int ans=n;
	for (int i=0;i<=n/d;i++) ans=min(ans,(n-i*d)%e);
	printf("%d\n",ans);
	return 0;
}