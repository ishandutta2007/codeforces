#include<bits/stdc++.h>
using namespace std;
#define ll long long

int sum[200010][26],n,m;
char s[200010];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);m=rd();
	for (int i=1;i<=n;i++)
	{
		memcpy(sum[i],sum[i-1],sizeof(sum[i]));
		sum[i][s[i]-'a']++;
	}
	while (m--)
	{
		int l=rd(),r=rd();
		if (l==r) { puts("Yes");continue; }
		int cnt=0;
		for (int i=0;i<26;i++) if (sum[r][i]-sum[l-1][i]>0) cnt++;
		if (cnt>=3) { puts("Yes");continue; }
		if (s[l]!=s[r]) { puts("Yes");continue; }
		puts("No");
	}
	return 0;
}