#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

using ll = long long;
#define ti(X) static_cast<int>(X)

const int MN = 1e5 + 100;
const int MV = 2e7 + 1000;

int b[MN];
bool u[MN];

int K, N, B, T;

int pre[MV];
int nex[MV];
ll dp[MN];

void precompute(void)
{
	for(int i = 0;i < B;i++)
		pre[i] = 0;
	for(int i = 0;i < N;i++)
		for(int& x = pre[b[i]];x <= i;x++)
			nex[b[i]*N+x] = i;
	for(int i = 0;i < B;i++)
		for(int j = pre[i];j < N;j++)
			nex[i*N+j] = -1;
}
void tryto(ll& a, const ll& b) {if(~b&&(!~a||b + 1 < a)) a = b + 1;}
ll get_nex(ll where, int num)
{
	if(where/N == T) return -1;
	int pos = ti(where%N);
	if(~nex[num*N + pos])
		return where/N*N + nex[num*N + pos];
	else
	{
		assert(~nex[num*N]);
		return where/N == T-1 ? -1 : nex[num*N] + (where/N + 1) * N;
	}
}
int solve(void)
{
	for(int i = 0;i < B;i++)
		u[i] = 0;
	for(int i = 0;i < N;i++)
	{
		scanf("%d", b + i);
		u[--b[i]] = 1;
	}
	precompute();
	for(int i = 0;i <= N;i++)
		dp[i] = -1LL;
	dp[0] = 0LL;
	for(int i = 0;i < B;i++)
		if(u[i])
			for(int j = N-1;j >= 0;j--)
				if(~dp[j])
					tryto(dp[j+1], get_nex(dp[j], i));//, printf("\t%d: %lld\n", j+1, dp[j+1]);
	//cout << "\t" << get_nex(5, 2) << " " << nex[2*N + 2] << "\n";
	for(int i = N;~i;i--)
		if(~dp[i])
			return printf("%d\n", i), 0;
	return assert(0), 0;
}
int main(void)
{
	scanf("%d%d%d%d", &K, &N, &B, &T);
	for(int i = 0;i < K;i++)
		solve();
	return 0;
}