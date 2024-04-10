#include<bits/stdc++.h>
using namespace std;
#define ll long long

int pre[1000010],n;
char s[1000010];

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
	int sum=0;
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='('?1:-1);
	if (pre[n]!=0) { puts("-1");return 0; }
	int ans=0;
	for (int i=0;i<n;i++) if (pre[i]==0)
	{
		int j=i+1,mn=0;
		while (pre[j]!=0) mn=min(mn,pre[j]),j++;
		if (mn<0) ans+=j-i;
	}
	printf("%d\n",ans);
	return 0;
}