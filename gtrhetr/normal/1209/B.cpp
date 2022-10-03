#include<bits/stdc++.h>
using namespace std;

int a[110],b[110],n;
bool bo[110];
char s[110];

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
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) bo[i]=(s[i]=='1');
	for (int i=1;i<=n;i++) a[i]=rd(),b[i]=rd();
	int ans=0;
	for (int i=1;i<=n;i++) ans+=bo[i];
	for (int i=1;i<=200;i++)
	{
		for (int j=1;j<=n;j++) if (i>=b[j]&&(i-b[j])%a[j]==0) bo[j]^=1;
		int res=0;
		for (int j=1;j<=n;j++) res+=bo[j];
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}