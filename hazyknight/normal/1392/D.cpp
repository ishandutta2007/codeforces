#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <bitset>

using namespace std;

const int MAXN = 200005;

int T,n,ans;
int f[MAXN];

char s[MAXN << 1];

void trans(char *S,int p,string s)
{
	if (p < s.size())
		return;
	int cnt = 0;
	for (int i = 0;i < s.size();i++)
		if (S[p - s.size() + i + 1] != s[i])
			cnt++;
	f[p] = min(f[p],cnt + f[p - s.size()]);
}

void solve(char *S)
{
	f[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		f[i] = 1e9;
		trans(S,i,"RL");
		trans(S,i,"RRL");
		trans(S,i,"RLL");
		trans(S,i,"RRLL");
	}
	ans = min(ans,f[n]);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s",&n,s + 1);
		for (int i = n + 1;i <= 2 * n;i++)
			s[i] = s[i - n];
		ans = 1e9;
		for (int i = 1;i <= min(n,4);i++)
			solve(s + i);
		printf("%d\n",ans);
	}
	return 0;
}