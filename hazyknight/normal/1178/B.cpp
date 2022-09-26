#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;

int n;

ll ans;
ll f[MAXN];
ll g[MAXN];

char s[MAXN];

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
		f[i] = f[i - 1] + (s[i] == 'v' && s[i - 1] == 'v');
	for (int i = n;i >= 1;i--)
		g[i] = g[i + 1] + (s[i] == 'v' && s[i + 1] == 'v');
	for (int i = 1;i <= n;i++)
		if (s[i] == 'o')
			ans += f[i - 1] * g[i + 1];
	printf("%lld\n",ans);
	return 0;
}