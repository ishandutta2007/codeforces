#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

template<typename T> bool ckmin(T& a, T b){return b<a?a=b,1:0;}

const int MN = 2e3+10, MC=26;
int T, N, c[MC], dp[MN][MN], ps[MN][MC], pt[MN][MC];
char s[MN], t[MN];
bool skip;

int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %s %s", &N, s, t);
		memset(c, 0, sizeof c);
		for(int i=0;i<N;++i) c[s[i]-='a']++;
		for(int i=0;i<N;++i) c[t[i]-='a']--;
		skip=0;
		for(int i=0;i<26;++i)
			if(c[i])
			{
				printf("-1\n");
				skip=1;
				break;
			}
		if(skip) continue;
		std::reverse(s, s+N);
		std::reverse(t, t+N);
		for(int i=0;i<N;++i)
		{
			memcpy(ps[i+1], ps[i], sizeof ps[i]);
			++ps[i+1][s[i]];
			memcpy(pt[i+1], pt[i], sizeof pt[i]);
			++pt[i+1][t[i]];
		}
		for(int i=0;i<=N;++i)
			for(int j=0;j<=i;++j)
				dp[i][j]=N;
		dp[0][0]=0;
		for(int i=0;i<=N;++i)
			for(int j=0;j<=i;++j)
			{
				if(i<N&&j<N&&s[i] == t[j])
					ckmin(dp[i+1][j+1], dp[i][j]);
				if(i<N)
					ckmin(dp[i+1][j], dp[i][j]+1);//pick up
				if(j<N&&ps[i][t[j]]-pt[j][t[j]]>0)
					ckmin(dp[i][j+1], dp[i][j]);//drop
				//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
			}
		printf("%d\n", dp[N][N]);
	}
	return 0;
}