#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

char s[MAXN];
int sum[MAXN][3][3];

void solve(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	for(int i=1; i<=n; ++i)
	{
		memcpy(sum[i], sum[i-1], sizeof(sum[i]));
		for(int j=0; j<3; ++j) ++sum[i][i%3][j];
		--sum[i][i%3][s[i] - 'a'];
	}
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l == r) printf("0\n");
		else if(l+1 == r) printf("%d\n",s[l] == s[r]? 1: 0);
		else
		{
			int ans = r-l+1;
			for(int i=0; i<3; ++i)
				for(int j=0; j<3; ++j) if(i != j)
				{
					int k = 0 ^ 1 ^ 2 ^ i ^ j;
					int cur = 0;
					cur += sum[r][l%3][i] - sum[l-1][l%3][i];
					cur += sum[r][(l+1)%3][j] - sum[l-1][(l+1)%3][j];
					cur += sum[r][(l+2)%3][k] - sum[l-1][(l+2)%3][k];
					ans = min(ans, cur);
				}
			printf("%d\n",ans);
		}
	}
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}