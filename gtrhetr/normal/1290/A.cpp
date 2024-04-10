#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

pii h[10010];

int mx1[4010][4010],mx2[4010][4010];
int num[10010],t,n,m,k;

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline void work()
{
	n=rd();m=rd();k=rd();k=min(k,m-1);
	for (int i=1;i<=n;i++) num[i]=rd();
	int ans=0;
	for (int i=0;i<=k;i++)
	{
		int res=1000000000;
		for (int j=0;j<=m-1-k;j++) res=min(res,max(num[i+j+1],num[n-(k-i)-(m-1-k-j)]));
		ans=max(ans,res);
	}
	printf("%d\n",ans);
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}