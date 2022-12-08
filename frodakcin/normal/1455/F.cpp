#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

const int MN = 5e2+10;
const int MK = 30;

int T, N, K;
char s[MN], ans[MN];

int delta(int v)
{
	if(v==0 || v+1==K) return 0;
	return v-1;
}

struct dps
{
	public:
		int v;
		int p;
		bool operator < (const dps& o) const {return v < o.v || !(o.v < v) && p < o.p;}
		bool operator == (const dps& o) const {return v == o.v && p == o.p;}
};

std::vector<dps> dp[MN];

void solve()
{
	scanf("%d%d %s", &N, &K, s);
	for(int i=0;i<N;++i) s[i]-=97;
	dp[0].push_back({0, 0});
	for(int i=0;i<N;++i)
	{
		std::vector<dps>& n=dp[i];
		std::sort(n.begin(), n.end());
		n.resize(std::distance(n.begin(), std::unique(n.begin(), n.end())));
		assert(!n.empty());

		if(i>=2) ans[i-2]=n[0].v+97;

		for(int j=0;j<n.size() && n[j].v == n[0].v;++j)
		{
			dps x = n[j];
			if(x.p<0)
			{
				dp[i+1].push_back({(-x.p)/K, (-x.p)%K});
				continue;
			}
			//d
			dp[i+1].push_back({x.p, delta(s[i])});

			//L
			if(i>0)
				dp[i+1].push_back({s[i], x.p});

			//Rd
			if(i+1<N)
				dp[i+1].push_back({x.p, -(delta(s[i+1])*K+s[i])});

			//RL
			if(i>0 && i+1<N)
				dp[i+1].push_back({s[i+1], -(x.p*K+s[i])});
		}
		n.clear();
	}

	assert(!dp[N].empty());
	std::nth_element(dp[N].begin(), dp[N].begin(), dp[N].end());
	ans[N-1]=dp[N][0].p+97;
	if(N>=2) ans[N-2]=dp[N][0].v+97;
	ans[N]=0;
	dp[N].clear();

	printf("%s\n", ans);
}

int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}