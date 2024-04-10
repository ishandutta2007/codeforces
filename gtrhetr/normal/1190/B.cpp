#include<bits/stdc++.h>
using namespace std;

int num[100010],n;

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
	int cnt=0;
	for (int i=1;i<n;i++) if (num[i]==num[i+1]) cnt++;
	if (cnt>=2) { puts("cslnb");return 0; }
	if (cnt==1)
	{
		int id=0;
		for (int i=1;i<n;i++) if (num[i]==num[i+1]) id=i;
		if (num[id]==0) { puts("cslnb");return 0; }
		num[id]--;
		if (id>1&&num[id]==num[id-1]) { puts("cslnb");return 0; }
		int sum=0;
		for (int i=n;i>=1;i-=2)
		{
			if (i>1) sum^=(num[i]-num[i-1]-1);
			else sum^=num[i];
		}
		if (sum&1) puts("cslnb");
		else puts("sjfnb");
		return 0;
	}
	int sum=0;
	for (int i=n;i>=1;i-=2)
	{
		if (i>1) sum^=(num[i]-num[i-1]-1);
		else sum^=num[i];
	}
	if (sum&1) puts("sjfnb");
	else puts("cslnb");
	return 0;
}