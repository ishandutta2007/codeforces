#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5005;

int n,m,ans;
int f[MAXN][MAXN];
int MAX[MAXN][MAXN];

char s[MAXN];
char t[MAXN];

int main()
{
	scanf("%d%d%s%s",&n,&m,s + 1,t + 1);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			if (s[i] == t[j])
				f[i][j] = max(2,MAX[i - 1][j - 1] + 4 - i - j);
			MAX[i][j] = max(MAX[i - 1][j],MAX[i][j - 1]);
			MAX[i][j] = max(MAX[i][j],f[i][j] + i + j);
			ans = max(ans,f[i][j]);
		}
	printf("%d\n",ans);
	return 0;
}