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

const int MAXN = 10005;
const ll MOD = 1000000007;

int n,m,t;
int cnt[125];

ll ans;

void dfs(int u,bitset<120> f,ll v,bool flag)
{
	if (flag)
		(ans += v) %= MOD;
	if (u > m - u)
		return;
	dfs(u + 1,f,v,0);
	if (f[m - u] || f[u] || !cnt[u])
		return;
	dfs(u + 1,f | ((f << u) | (f >> (m - u))) | ((f >> u) | (f << (m - u))),v * cnt[u] % MOD,1);
}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	while (t--)
	{
		int x;
		scanf("%d",&x);
		x %= m;
		x = min(x,m - x);
		cnt[x]++;
	}
	bitset<120> r;
	r[0] = 1;
	dfs(1,r,1,1);
	printf("%lld\n",ans);
	return 0;
}