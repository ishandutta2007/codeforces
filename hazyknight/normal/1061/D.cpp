#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 1000000007;

int n,x,y;

pair<int,int> ser[MAXN];

ll ans;

priority_queue<int,vector<int>,greater<int> > Q1;
priority_queue<int> Q2;

int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for (int i = 1;i <= n;i++)
		scanf("%d%d",&ser[i].first,&ser[i].second);
	sort(ser + 1,ser + n + 1);
	for (int i = 1;i <= n;i++)
	{
		while (!Q1.empty() && Q1.top() < ser[i].first)
		{
			Q2.push(Q1.top());
			Q1.pop();
		}
		while (!Q2.empty() && (ll)(ser[i].first - Q2.top()) * y > x)
			Q2.pop();
		if (Q2.empty())
			(ans += x + (ll)(ser[i].second - ser[i].first) * y) %= MOD;
		else
		{
			(ans += (ll)(ser[i].second - Q2.top()) * y) %= MOD;
			Q2.pop();
		}
		Q1.push(ser[i].second);
	}
	printf("%I64d\n",ans);
	return 0;
}