#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MN = 18;

int N;
ll cnt[1<<MN][MN], dp[1<<MN-1][MN];
std::vector<int> mlen[MN+1];
std::vector<int> inc[1<<MN], exc[1<<MN];
bool conn[MN][MN];

std::vector<int> stk;
void dfs(int n)
{
	if(n == N)
	{
		ll ans = 0LL;
		for(int i = 0;i < N;++i)
			ans += cnt[(1<<N)-1][i];
		int m;
		do
		{
			m = 0;
			for(int x : stk)
				m = m<<x|((1<<x-1)-1);
			dp[m][0] += ans;
		}
		while (std::next_permutation(stk.begin(), stk.end(), std::greater<int>()));
		return;
	}
	stk.push_back(1);
	for(int m : mlen[n])
	{
		ll sm = 0LL;
		for(int i : inc[m])
			sm += cnt[m][i];
		for(int j : exc[m])
			cnt[m|1<<j][j] += sm;
	}
	dfs(n+1);
	stk.pop_back();
	for(int m : mlen[n+1])
		for(int i : inc[m])
			cnt[m][i] = 0LL;

	if(stk.size() == 1 || stk.back() < stk[stk.size()-2])
	{
		++stk.back();
		for(int m : mlen[n])
			for(int i : inc[m])
				for(int j : exc[m])
					if(conn[i][j])
						cnt[m|1<<j][j] += cnt[m][i];
		dfs(n+1);
		--stk.back();
		for(int m : mlen[n+1])
			for(int i : inc[m])
				cnt[m][i] = 0LL;
	}
}

int main(void)
{
	scanf("%d", &N);
	{
		char a;
		for(int i = 0;i < N;++i)
			for(int j = 0;j < N;++j)
				scanf(" %c", &a), conn[i][j] = a == '1';
	}
	for(int i = 0;i < 1<<N;++i)
		mlen[__builtin_popcount(i)].push_back(i);
	for(int i = 0;i < 1<<N;++i)
		for(int j = 0;j < N;++j)
			if(i>>j&1) inc[i].push_back(j);
			else exc[i].push_back(j);

	for(int i = 0;i < N;++i)
		cnt[1<<i][i] = 1LL;
	stk.push_back(1);
	dfs(1);

	//for(int i = 0;i < 1<<N-1;++i) printf("%d: %d\n", i, dp[i][0]);
	for(int i = 0;i < N-1;++i)
		for(int m = 0;m < 1<<N-1;++m)
			if(m>>i&1)
				dp[m][i+1] = dp[m][i];
			else
				dp[m][i+1] = dp[m][i] - dp[m|1<<i][i];
	for(int i = 0;i < 1<<N-1;++i)
		printf("%lld ", dp[i][N-1]);
	return 0;
}