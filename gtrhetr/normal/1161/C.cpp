#include<bits/stdc++.h>
using namespace std;

int num[60],n;

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
	for (int i=1;i<=n;i++) num[i]=rd();
	int mn=100,cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (num[i]<mn) mn=num[i],cnt=1;
		else if (num[i]==mn) cnt++;
	}
	puts((cnt<=n/2)?"Alice":"Bob");
	return 0;
}