#include<bits/stdc++.h>
using namespace std;

int mn1[100010][2],mx1[100010][2],mn2[100010][2],mx2[100010][2];
int pre[100010],suf[100010],mn[2],mx[2],n,k;
char s[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();k=rd();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+s[i]-'0';
	for (int i=n;i;i--) suf[i]=suf[i+1]+s[i]-'0';
	mn1[0][0]=mn1[0][1]=n+1;
	for (int i=1;i<=n;i++)
	{
		mn1[i][0]=mn1[i-1][0];
		mn1[i][1]=mn1[i-1][1];
		mx1[i][0]=mx1[i-1][0];
		mx1[i][1]=mx1[i-1][1];
		int now=s[i]-'0';
		mn1[i][now]=min(mn1[i][now],i);
		mx1[i][now]=i;
	}
	mn2[n+1][0]=mn2[n+1][1]=n+1;
	for (int i=1;i<=n;i++)
	{
		mn2[i][0]=mn2[i+1][0];
		mn2[i][1]=mn2[i+1][1];
		mx2[i][0]=mx2[i+1][0];
		mx2[i][1]=mx2[i+1][1];
		int now=s[i]-'0';
		mn2[i][now]=i;
		mx2[i][now]=max(mx2[i][now],i);
	}
	bool flag=false;
	for (int i=1;i+k-1<=n;i++)
	{
		if (!pre[i-1]&&!suf[i+k]) { puts("tokitsukaze");return 0; }
		if (pre[i-1]==i-1&&suf[i+k]==n-(i+k)+1) { puts("tokitsukaze");return 0; }
		int h1=min(mn1[i-1][0],mn2[i+k][0]),h2=max(mx1[i-1][0],mx2[i+k][0]);
		int hh1=min(mn1[i-1][1],mn2[i+k][1]),hh2=max(mx1[i-1][1],mx2[i+k][1]);
		if (h2-h1+1>k||hh2-hh1+1>k) flag=true;
	}
	if (flag) puts("once again");
	else puts("quailty");
	return 0;
}