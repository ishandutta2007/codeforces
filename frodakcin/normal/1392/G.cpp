#include <cstdio>
#include <cstring>
#include <numeric>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MK = 20;
const int MN = 1e6+10;
const int INF = 0x3f3f3f3f;

int N, M, K, a[MN], b[MN], dp[MK+2][1<<MK], p[MK], sv[MN], tv[MN], f=-1, f1, f2;
char s[MK+2], t[MK+2];

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	scanf(" %s %s", s, t);
	for(int i=0;i<K;++i)
		sv[N]|=s[i]-'0'<<i, tv[N]|=t[i]-'0'<<i;
	for(int i=0;i<N;++i)
		scanf("%d%d", a+i, b+i), --a[i], --b[i];
	std::iota(p, p+K, 0);
	for(int i=N-1;i>=0;--i)
	{
		std::swap(p[a[i]], p[b[i]]);
		for(int j=0;j<K;++j)
			sv[i]|=s[j]-'0'<<p[j];
		for(int j=0;j<K;++j)
			tv[i]|=t[j]-'0'<<p[j];
	}
	memset(dp[0], 0x3f, sizeof dp[0]);
	memset(dp[1], -1, sizeof dp[1]);
	for(int i=N;i>=0;--i) dp[0][sv[i]]=i;
	for(int i=0;i<=N;++i) dp[1][tv[i]]=i;
	for(int i=(1<<K)-1;i>=0;--i)
	{
		if(dp[1][i]-dp[0][i]>=M)
			if(ckmax(f, (int)__builtin_popcount(i)))
				f1=dp[0][i], f2=dp[1][i];
		for(int j=0;j<K;++j)
			if(i>>j&1)
			{
				ckmin(dp[0][i^1<<j], dp[0][i]);
				ckmax(dp[1][i^1<<j], dp[1][i]);
			}
	}
	printf("%d\n%d %d\n", K-__builtin_popcount(tv[0])-__builtin_popcount(sv[0])+2*f, f1+1, f2);
	return 0;
}