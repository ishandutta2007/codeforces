#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
#define maxn 100005
using namespace std;
struct th
{
	
	int tm;
	int ids[105];
	int num;
	bool operator<(const th&a)const
	{
		return tm > a.tm;
	}
};
priority_queue <th> p;
int n, q;
int t[maxn], k[maxn], d[maxn];
bool can[105];
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 0; i < q; i++)
		scanf("%d%d%d", &t[i], &k[i], &d[i]);
	int nows = n;
	for(int i = 1; i <= n; i++)
		can[i] = true;
	for(int i = 0; i < q; i++)
	{
		while(!p.empty())
		{
			if(p.top().tm <= t[i])
			{
				for(int j = 0; j < p.top().num; j++)
					can[p.top().ids[j]] = true;
				nows += p.top().num;
				p.pop();
			}
			else
				break;
		}
		if(nows < k[i])
		{
			printf("-1\n");
			continue;
		}
		th now;
		now.num = k[i];
		int npl = 0;
		now.tm = t[i] + d[i];
		nows -= k[i];
		int sum = 0;
		for(int j = 1; j <= n; j++)
		{
			if(npl >= k[i]) break;
			if(can[j]) 
			{
				now.ids[npl] = j;
				npl++;
				sum += j;
				can[j] = false;
			}
		}
		p.push(now);
		printf("%d\n", sum);
	}
	return 0;
}