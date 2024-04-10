#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define next grkjbejrhbgeh

int fail[500010],sum[2],n,m;
char s[500010],t[500010];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	if (n<m)
	{
		printf("%s\n",s+1);
		return 0;
	}
	for (int i=1;i<=n;i++) sum[s[i]-'0']++;
	fail[1]=0;
	for (int i=2,j=0;i<=m;i++)
	{
		while (j&&t[j+1]!=t[i]) j=fail[j];
		if (t[j+1]==t[i]) j++;
		fail[i]=j;
	}
	int now=0;
	for (int i=1;i<=n;i++)
	{
		if (now==m) now=fail[now];
		if (sum[t[now+1]-'0']) putchar(t[now+1]),sum[t[now+1]-'0']--,now++;
		else
		{
			char hh=(t[now+1]=='0')?'1':'0';
			putchar(hh);sum[hh-'0']--;
			while (now&&t[now+1]!=hh) now=fail[now];
			if (t[now+1]==hh) now++;
		}
	}
	return 0;
}