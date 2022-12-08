#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>

template<class T> bool ckmax(T* a, T b){return *a<b?*a=b,1:0;}
template<class T> bool ckmin(T* a, T b){return b<*a?*a=b,1:0;}

int dig[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};// this better fucking be right
int cnt[10];

const int MN = 2e3 + 10;
const int MK = 2e3 + 200;

int N, K;
int dp[MN][MK];
int pr[MN][MK];
int ord[MN];
int a[MN];
char ans[MN], inp[15];
int main(void)
{
	for(int i = 0;i < 10;++i)
		cnt[i] = __builtin_popcount(dig[i]);
	memset(dp, -1, sizeof(dp));
	memset(pr, -1, sizeof(pr));
	std::iota(ord, ord+MN, 0);
	scanf("%d%d", &N, &K);
	for(int i = 0;i < N;++i)
	{
		scanf(" %s", inp);
		for(int j = 0;j < 7;++j)
			if(inp[7-j-1] == '1')
				a[i] |= 1<<j;
	}
	dp[0][0] = 0;
	pr[0][0] = 0;
	for(int i = 0;i < N;++i)
	{
		std::sort(ord, ord+K+1, [&](int x, int y){return pr[i][x] > pr[i][y];});
		for(int j = 0;j <= K;++j)
			if(~pr[i][ord[j]])
				pr[i][ord[j]] = K-j;
			else
				break;

		int nm = __builtin_popcount(a[i]);
		for(int k = 0;k < 10;++k)
			for(int j = 0;j <= K;++j)
				if(~dp[i][j])
				{
					if((a[i]&dig[k]) == a[i])
					{
						int q = j + cnt[k] - nm;
						if(q <= K && ckmax(pr[i+1]+q, pr[i][j]<<4|k))
							dp[i+1][q] = k | j << 4;
					}
				}
	}
	if(!~dp[N][K])
		return printf("-1\n"), 0;
	for(int n = N, k = K;n;--n)
	{
		int v = dp[n][k];
		ans[n-1] = '0' + (v&0xf);
		k = v>>4;
	}
	printf("%s\n", ans);
	return 0;
}