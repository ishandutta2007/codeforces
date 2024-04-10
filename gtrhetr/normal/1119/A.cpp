#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mn[300010],mx[300010];
int num[300010],n;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++)
	{
		int now=1;
		while (num[now]==i) now++;
		mn[i]=now;
	}
	for (int i=1;i<=n;i++)
	{
		int now=n;
		while (num[now]==i) now--;
		mx[i]=now;
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,max(abs(i-mn[num[i]]),abs(mx[num[i]]-i)));
	printf("%d\n",ans);
	return 0;
}