#include <cstdio>
#include <cstring>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 2e5+100;

int T, N, f, dp[MN];
char s[MN];

void solve()
{
	memset(dp+1, 0x3f, N*sizeof*dp);
	dp[0]=0;
	for(int i=2;i<=N;++i)
	{
		if(i>=2)
		{
			ckmin(dp[i], dp[i-2]+(s[i-2]!='R')+(s[i-1]!='L'));
		}
		if(i>=3)
		{
			ckmin(dp[i], dp[i-3]+(s[i-3]!='R')+(s[i-2]!='R')+(s[i-1]!='L'));
			ckmin(dp[i], dp[i-3]+(s[i-3]!='R')+(s[i-2]!='L')+(s[i-1]!='L'));
		}
		if(i>=4)
		{
			ckmin(dp[i], dp[i-4]+(s[i-4]!='R')+(s[i-3]!='R')+(s[i-2]!='L')+(s[i-1]!='L'));
		}
	}
	ckmin(f, dp[N]);
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		f=N;
		scanf(" %s", s);
		solve(); std::rotate(s, s+1, s+N);
		solve(); std::rotate(s, s+1, s+N);
		solve(); std::rotate(s, s+1, s+N);
		solve(); std::rotate(s, s+1, s+N);
		solve();
		printf("%d\n", f);
	}
	return 0;
}