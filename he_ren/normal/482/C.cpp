#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long double ldb;
typedef double db;
typedef long long ll;
const int MAXN = 50 + 5;
const int MAXM = 20 + 5;
const int ALL = (1<<20) + 5;

#define bit(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

char s[MAXN][MAXM];
ldb dp[ALL];
ll bad[ALL];
int totBad[ALL];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	int m = strlen(s[1]+1);
	int all = (1<<m)-1;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
		{
			int same=0;
			for(int k=1; k<=m; ++k)
				if(s[i][k]==s[j][k])
					same |= 1<<(k-1);
			bad[same] |= 1ll<<(i-1);
			bad[same] |= 1ll<<(j-1);
		}
	
	for(int mask=all; mask>=0; --mask)
	{
		for(int i=0; i<m; ++i)
			if(bit(mask,i))
				bad[mask^(1<<i)] |= bad[mask];
		for(int i=0; i<n; ++i)
			if(bit(bad[mask],i))
				++totBad[mask];
	}
	
	for(int mask=all-1; mask>=0; --mask)
	{
		int cnt=0;
		for(int i=0; i<m; ++i)
			if(!bit(mask,i))
				dp[mask] += dp[mask|(1<<i)],
				++cnt;
		dp[mask] /= cnt;
		dp[mask] += (ldb)totBad[mask]/n;
	}
	printf("%.20lf",(db)dp[0]);
	return 0;
}

/*
10
aababbbaabaababababa
ababaababbabaaababbb
ababbababaaaaaabbbab
ababbbbabaabaaababaa
abbabbbaabbbbbbbaaba
baaabbabababbabbaaaa
bababbbbbbaaaabbaaba
babbaabaaabaaaabbaab
babbbaababaabbbbbaab
bbbbabaaababaabbabab
*/