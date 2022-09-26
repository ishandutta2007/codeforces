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

const int MAXN = 200005;

struct Station
{
	int x,p;
	
	bool operator < (const Station &a)const
	{
		return x < a.x;
	}
}s[MAXN];

int d,n,m,top;
int S[MAXN];
int nxt[MAXN];

ll ans;

int main()
{
	scanf("%d%d%d",&d,&n,&m);
	for (int i = 1;i <= m;i++)
		scanf("%d%d",&s[i].x,&s[i].p);
	sort(s + 1,s + m + 1);
	s[++m] = (Station){d,0};
	for (int i = 1;i <= m;i++)
	{
		while (top && s[S[top]].p > s[i].p)
			nxt[S[top--]] = i;
		S[++top] = i;
	}
	int pos = 0,cur = n;
	for (int i = 1;i <= m;i++)
	{
		cur -= s[i].x - pos;
		pos = s[i].x;
		if (cur < 0)
		{
			puts("-1");
			return 0;
		}
		if (!nxt[i] || s[nxt[i]].x - pos > n)
		{
			ans += (ll)(n - cur) * s[i].p;
			cur = n;
		}
		else
		{
			int t = max(0,s[nxt[i]].x - pos - cur);
			ans += (ll)t * s[i].p;
			cur += t;
		}
	}
	printf("%lld\n",ans);
	return 0;
}