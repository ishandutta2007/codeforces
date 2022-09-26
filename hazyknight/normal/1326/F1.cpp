#pragma GCC optimize(3)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 14;

int n;
int rev[1 << MAXN];

ll ans[1 << MAXN];
ll f[1 << MAXN][MAXN][1 << 6];

char s[MAXN][MAXN];

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%s",s[i]);
	int N = (n + 1) / 2 - 1,N_ = n - 2 - N;
	for (int i = 1;i < (1 << N);i++)
		rev[i] = (rev[i >> 1] >> 1) + (i & 1) * (1 << (N - 1));
	for (int i = 0;i < (1 << N);i++)
	{
		for (int j = 0;j < n;j++)
			f[1 << j][j][i] = 1;
		for (int j = 1;j < (1 << n);j++)
		{
			int t = popcount(j) - 1;
			if (t >= N)
				continue;
			for (int k = 0;k < n;k++)
				if ((j >> k & 1) && f[j][k][i])
					for (int l = 0;l < n;l++)
						if ((~j >> l & 1) && s[k][l] - '0' == (i >> t & 1))
							f[j | (1 << l)][l][i] += f[j][k][i];
		}
	}
	for (int S = 0;S < (1 << n);S++)
		if (popcount(S) == N + 1)
			for (int k = 0;k < n;k++)
				if (S >> k & 1)
					for (int l = 0;l < n;l++)
						if (~S >> l & 1)
							for (int i = 0;i < (1 << N);i++)
								if (f[S][k][i])
									for (int j = 0;j < (1 << N_);j++)
										if (f[((1 << n) - 1) ^ S][l][j])
											ans[(rev[i] << N_ << 1) | ((s[k][l] - '0') << N_) | j] += f[S][k][i] * f[((1 << n) - 1) ^ S][l][j];
	for (int i = 0;i < (1 << (n - 1));i++)
		printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}