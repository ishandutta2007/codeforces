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

const int MAXN = 1000005;
const ll MOD = 1000000007;

int T,x;

char s[MAXN];
char t[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&x,s + 1);
		ll n = strlen(s + 1);
		int cur = 0,c = 0,N = n;
		while (cur != x)
		{
			cur++;
			int tot = 0;
			if (N < x && s[cur] != '1')
			{
				for (int i = cur + 1;i <= N;i++)
					t[++tot] = s[i];
			}
			(n += (n - cur) * (s[cur] - '0' - 1)) %= MOD;
			for (int i = 1;i <= s[cur] - '0' - 1 && N < x;i++)
				for (int j = 1;j <= tot && N < x;j++)
					s[++N] = t[j];
		}
		printf("%lld\n",(n + MOD) % MOD);
	}
	return 0;
}