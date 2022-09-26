#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n;

char s[MAXN];
char t[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s%s",&n,s + 1,t + 1);
		int ans = n + 1;
		int cnt[2][2] = {0};
		for (int i = 1;i <= n;i++)
			cnt[s[i] - '0'][t[i] - '0']++;
		if (cnt[0][1] == cnt[1][0])
			ans = min(ans,cnt[0][1] * 2);
		for (int i = 1;i <= n;i++)
			if (s[i] == '1')
			{
				cnt[1][t[i] - '0']--;
				swap(cnt[0],cnt[1]);
				cnt[1][t[i] - '0']++;
				if (cnt[0][1] == cnt[1][0])
					ans = min(ans,cnt[0][1] * 2 + 1);
				cnt[1][t[i] - '0']--;
				swap(cnt[0],cnt[1]);
				cnt[1][t[i] - '0']++;
			}
		printf("%d\n",(ans > n ? -1 : ans));
	}
	return 0;
}