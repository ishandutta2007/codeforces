#include<bits/stdc++.h>
using namespace std;

int num[110],t,n,d; 

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{
	n=rd();d=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int ans=num[1];
	for (int i=2;i<=n;i++)
	{
		int now=min(d/(i-1),num[i]);
		d-=(i-1)*now;ans+=now;
	}
	printf("%d\n",ans);
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}