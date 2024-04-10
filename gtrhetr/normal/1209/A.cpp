#include<bits/stdc++.h>
using namespace std;

int num[110],n;
bool vis[110];

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
	sort(num+1,num+n+1);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		bool flag=false;
		for (int j=1;j<=num[i];j++) if (num[i]%j==0&&vis[j]) flag=true;
		ans+=!flag;
		if (!flag) vis[num[i]]=true;
	}
	printf("%d\n",ans);
	return 0;
}