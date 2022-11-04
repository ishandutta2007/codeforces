#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n;

ll x,y,ans;
ll f[MAXN];
ll g[MAXN];
ll pre[MAXN];
ll suf[MAXN];

char s[MAXN];

int main()
{
	ans = 1e18;
	scanf("%s%lld%lld",s + 1,&x,&y);
	n = strlen(s + 1);
	f[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		char cur = (s[i] != '1' ? '0' : '1');
		pre[i] = pre[i - 1] + (cur == '0');
		f[i] = f[i - 1] + (cur == '0' ? y * (i - 1 - pre[i - 1]) : x * pre[i - 1]);
	}
	for (int i = n;i >= 1;i--)
	{
		char cur = (s[i] != '0' ? '1' : '0');
		suf[i] = suf[i + 1] + (cur == '1');
		g[i] = g[i + 1] + (cur == '1' ? y * (n - i - suf[i + 1]) : x * suf[i + 1]);
	}
	for (int i = 0;i <= n;i++)
		ans = min(ans,f[i] + g[i + 1] + x * pre[i] * suf[i + 1] + y * (i - pre[i]) * (n - i - suf[i + 1]));
		
	f[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		char cur = (s[i] != '0' ? '1' : '0');
		pre[i] = pre[i - 1] + (cur == '0');
		f[i] = f[i - 1] + (cur == '0' ? y * (i - 1 - pre[i - 1]) : x * pre[i - 1]);
	}
	for (int i = n;i >= 1;i--)
	{
		char cur = (s[i] != '1' ? '0' : '1');
		suf[i] = suf[i + 1] + (cur == '1');
		g[i] = g[i + 1] + (cur == '1' ? y * (n - i - suf[i + 1]) : x * suf[i + 1]);
	}
	for (int i = 0;i <= n;i++)
		ans = min(ans,f[i] + g[i + 1] + x * pre[i] * suf[i + 1] + y * (i - pre[i]) * (n - i - suf[i + 1]));
		
	printf("%lld\n",ans);
	return 0;
}