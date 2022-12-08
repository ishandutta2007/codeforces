#include <cstdio>
#include <map>

using ll = long long;
const int MN=1e2+10;
int T, N, M;
ll a, ans;
std::map<ll, ll> dp[MN][MN];

void put(std::map<ll, ll> &m, ll k, ll v)
{
	auto it = m.find(k);
	if(it==m.end())
		m.insert({k, v});
	else
		if(v<it->second)
			it->second=v;
}
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
			{
				scanf("%lld", &a);
				if(!i&&!j)
					put(dp[i][j], a, 0);
				if(i)
					for(auto x:dp[i-1][j])
						if(x.first < a)
							put(dp[i][j], x.first+1, a-1-x.first+x.second);
						else
							put(dp[i][j], a, x.second+(x.first-a+1)*(i+j));
				if(j)
					for(auto x:dp[i][j-1])
						if(x.first < a)
							put(dp[i][j], x.first+1, a-1-x.first+x.second);
						else
							put(dp[i][j], a, x.second+(x.first-a+1)*(i+j));
			}
		ans=8e18;
		for(auto x:dp[N-1][M-1])
			ans = std::min(ans, x.second);
		printf("%lld\n", ans);
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				dp[i][j].clear();
	}
	return 0;
}