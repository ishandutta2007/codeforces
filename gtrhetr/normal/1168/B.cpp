#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mn[300010],n;
char s[300010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n+1;i++) mn[i]=n+1;
	for (int i=2;i<n;i++)
	{
		for (int j=1;j<=10;j++)
		{
			if (i-j<=0||i+j>n) continue;
			if (s[i-j]==s[i]&&s[i+j]==s[i]) mn[i-j]=min(mn[i-j],i+j);
		}
	}
	for (int i=n;i;i--) mn[i]=min(mn[i],mn[i+1]);
	ll ans=0;
	for (int i=1;i<=n;i++) ans+=n-mn[i]+1;
	printf("%lld\n",ans);
	return 0;
}