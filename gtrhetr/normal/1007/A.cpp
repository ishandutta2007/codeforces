#include<bits/stdc++.h>
using namespace std;
#define ll long long

int num[100010],n;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	sort(num+1,num+n+1);
	int ans=0;
	int now=n;
	for (int i=n;i;i--)
	{
		while (now>=i) now--;
		while (now>0&&num[now]>=num[i]) now--;
		if (now<=0) break;
		ans++;now--;
	}
	printf("%d\n",ans);
	return 0;
}