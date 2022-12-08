#include <cstdio>
#include <cstring>
#include <cassert>
#include <functional>
#include <deque>

using ll = long long;

const int MV = 1e6;
const int p10[] = {1, 10, 100, 1000, 10000, 100000};

int K, Q, F[6];
ll dp[MV];

ll val(int x)
{
	ll f=0;
	for(int i=0;x;++i, x/=10)
	{
		int d=x%10;
		if(d%3 == 0)
			f += (ll)F[i]*d/3;
	}
	return f;
}

struct info
{
	public:
		int k; ll v;
};
std::deque<info> q;

int main()
{
	scanf("%d", &K);
	for(int i=0;i<6;++i)
		scanf("%d", F+i);
	--K; K*=3;
	for(int i=0;i<MV;++i)
		dp[i]=val(i);
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<3*p10[i];++j)
		{
			int mv=1+(MV-j-1)/(3*p10[i]);
			std::function<ll&(int)> get = [&](int x)->ll&{assert(j+x*3*p10[i] < MV); return dp[j+x*3*p10[i]];};
			for(int k=0;k<mv;++k)
			{
				for(;!q.empty() && k-q.front().k > K;)q.pop_front();
				for(;!q.empty() && get(k) >= q.back().v + (ll)F[i]*(k-q.back().k);) q.pop_back();
				q.push_back({k, get(k)});
				get(k) = q.front().v + (ll)F[i]*(k-q.front().k);
			}
			q.clear();
		}
	}
	scanf("%d", &Q);
	for(int i=0;i<Q;++i)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
	return 0;
}