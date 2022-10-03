#include<bits/stdc++.h>
using namespace std;
#define ll long long

int pre[1000010],suf[1000010],n;
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
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='v'&&s[i-1]=='v');
	for (int i=n;i;i--) suf[i]=suf[i+1]+(s[i]=='v'&&s[i+1]=='v');
	ll ans=0;
	for (int i=1;i<=n;i++) if (s[i]=='o') ans+=(ll)pre[i-1]*suf[i+1];
	printf("%lld\n",ans);
	return 0;
}