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

const int MAXN = 100005;

int n;

ll ans;
ll cnt[26];
ll f[26][26];

char s[MAXN];

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j < 26;j++)
			f[s[i] - 'a'][j] += cnt[j];
		cnt[s[i] - 'a']++;
	}
	for (int i = 0;i < 26;i++)
		ans = max(ans,cnt[i]);
	for (int i = 0;i < 26;i++)
		for (int j = 0;j < 26;j++)
			ans = max(ans,f[i][j]);
	printf("%lld\n",ans);
	return 0;
}