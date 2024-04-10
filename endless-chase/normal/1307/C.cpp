#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,cnt;
long long cur,ans;
char s[111111];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for (int i=0;i<26;i++)
	{
		cnt=0;
		for (int j=0;j<n;j++)
		{
			if (s[j]==i+'a') cnt++;
		}
		ans=max(ans,(long long)cnt);
	}
	for (int i=0;i<26;i++)
	{
		for (int j=0;j<26;j++)
		{
			cnt=0;cur=0;
			for (int k=0;k<n;k++)
			{
				if (s[k]==j+'a') cur+=cnt;
				if (s[k]==i+'a') cnt++;
			}
			ans=max(ans,cur);
		}
	}
	printf("%lld\n",ans);
	return Accepted;
}