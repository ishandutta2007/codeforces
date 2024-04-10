#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[100010][11],n;
char s[100010];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]-'0'>0) f[i][s[i]-'0']++;
		for (int j=0;j<=10;j++) if (s[i]-'0'<j) f[i][(j*(j-1)/2+s[i]-'0'+10)%11]+=f[i-1][j];
		for (int j=0;j<=10;j++) ans+=f[i][j];
	}
	printf("%lld\n",ans);
	return 0;
}