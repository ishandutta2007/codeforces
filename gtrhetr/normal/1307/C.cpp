#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll S[26][26];
int cnt[26],n;
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
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
	ll ans=0;
	for (int i=0;i<26;i++) ans=max(ans,(ll)cnt[i]);
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++) S[j][s[i]-'a']+=cnt[j];
		cnt[s[i]-'a']++;
	}
	for (int i=0;i<26;i++) for (int j=0;j<26;j++) ans=max(ans,S[i][j]);
	printf("%lld\n",ans);
	return 0;
}