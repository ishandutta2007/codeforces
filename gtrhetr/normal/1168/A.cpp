#include<bits/stdc++.h>
using namespace std;

int mn[300010];
int num[300010],n,m;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool check(int mid)
{
	if (num[1]+mid>=m) mn[1]=0;
	else mn[1]=num[1];
	for (int i=2;i<=n;i++)
	{
		int st=num[i],ed=(num[i]+mid)%m;
		if (st<=ed)
		{
			if (ed<mn[i-1]) return false;
			mn[i]=max(st,mn[i-1]);
		}
		else
		{
			if (mn[i-1]<=ed) mn[i]=mn[i-1];
			else if (mn[i-1]>=st) mn[i]=mn[i-1];
			else mn[i]=st;
		}
	}
	return true;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	int l=0,r=m-1;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}