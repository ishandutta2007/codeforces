#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1000 + 5;

char s[MAXN][MAXN];
int ans[MAXN][MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	
	--d;
	for(int i=1; i<=d; ++i)
		s[1][n-i+1] = s[n-i+1][1] = '0';
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			ans[i][j] = 0;
	
	static int pos[MAXN];
	for(int i=1; i<=d; ++i)
		pos[i] = n-d+i;
	for(int i=1; i<=n; ++i)
	{
		pos[0] = 0; pos[d+1] = n;
		for(int j=d+1; j>=1; --j)
		{
			if(pos[j] == 0) continue;
			int k = pos[j-1]+1;
			while(k <= pos[j] && s[i][k] == '1') ++k;
			if(j > d)
			{
				if(k <= pos[j])
				{
					printf("NO\n");
					return;
				}
				continue;
			}
			k = min(k, pos[j]);
			while(pos[j] > k) ans[i][pos[j]--] = 1;
			ans[i][pos[j]] = 1;
			if(i == n-d+j) pos[j] = 0;
		}
	}
	
	printf("YES\n");
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=n; ++j)
			putchar(ans[i][j] + '0');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}