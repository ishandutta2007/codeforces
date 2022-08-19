#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define maxn 300005
using namespace std;
struct th
{
	int id, num;
	bool operator < (const th &a)const
	{
		return num < a.num;
	}
};
priority_queue <th> q;
int c[maxn], n, k;
int tm[maxn];

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	int pl = 1;
	ll ans = 0;
	for(int i = k + 1; i <= k + n; i++)
	{
		while(pl <= n && pl <= i)
		{
			th n1;
			n1.id = pl, n1.num = c[pl], q.push(n1);
			pl++;
		}
		th n1 = q.top();
		q.pop();
		tm[n1.id] = i;
		ans += n1.num * (ll)(tm[n1.id] - n1.id);
	}
	printf("%I64d\n", ans);
	for(int i = 1; i <= n; i++)
		printf("%d ", tm[i]);
	return 0;
}