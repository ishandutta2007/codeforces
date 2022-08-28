#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int MAXN = 200005;

int n,ans;
int cnt[MAXN];

char s[MAXN];

int main()
{
	scanf("%d%s",&n,s + 1);
	for (int i = 1;i <= n;i++)
		if (n % i == 0)
		{
			for (int j = 0;j < i;j++)
				cnt[j] = 0;
			for (int j = 1;j <= n;j++)
				cnt[j % i] ^= s[j] - '0';
			bool ok = 1;
			for (int j = 0;j < i;j++)
				if (cnt[j])
				{
					ok = 0;
					break;
				}
			if (ok)
			{
				for (int j = i;j <= n;j += i)
					if (__gcd(n,j) == i)
						ans++;
			}
		}
	printf("%d\n",ans);
	return 0;
}