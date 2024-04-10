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

int T,tot;
int v[25];
int cnt[25];

ll n,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld",&n);
		tot = 0;
		for (int i = 0;i <= 20;i++)
			cnt[i] = 0;
		for (int i = 2;n;i++)
		{
			v[++tot] = n % i;
			cnt[n % i]++;
			n /= i;
		}
		sort(v + 1,v + tot + 1);
		ans = 0;
		for (int lst = 1;lst <= tot;lst++)
		{
			if (!v[lst])
				continue;
			ll prd = 1;
			for (int i = 2,j = 0;i <= tot;i++)
			{
				while (j + 1 <= tot && v[j + 1] < i)
					j++;
				prd *= j - i + 2 - (j >= lst);
			}
			ans += prd;
		}
		for (int i = 0;i <= 20;i++)
			for (int j = 1;j <= cnt[i];j++)
				ans /= j;
		printf("%lld\n",ans - 1);
	}
	return 0;
}