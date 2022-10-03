#include<bits/stdc++.h>
using namespace std;

int num[100010],t,n,x;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{
	n=rd();x=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int ans=1000000001;
	for (int i=1;i<=n;i++)
	{
		if (x<num[i]) ans=min(ans,2);
		else ans=min(ans,x/num[i]+(bool)(x%num[i]));
	}
	printf("%d\n",ans);
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}