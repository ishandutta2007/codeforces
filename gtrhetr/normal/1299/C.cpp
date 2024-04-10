#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll num[1000010],sum[1000010],st[1000010],n,top;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool check(int l1,int r1,int l,int r)
{
	return (sum[r1]-sum[l1-1])*(r-l+1)<=(sum[r]-sum[l-1])*(r1-l1+1);
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd(),sum[i]=sum[i-1]+num[i];
	top=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&check(st[top]+1,i,st[top-1]+1,st[top])) top--;
		st[++top]=i;
	}
	for (int i=1;i<=top;i++)
	{
		double now=(double)(sum[st[i]]-sum[st[i-1]])/(st[i]-st[i-1]);
		for (int j=1;j<=st[i]-st[i-1];j++) printf("%.10lf\n",now);
	}
	return 0;
}