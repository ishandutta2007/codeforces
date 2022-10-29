#include <cstdio>
#include <queue>
const int N = 2e5;
const long long INF = 1e18;
long long ans[N];

int main()
{
	int n, p; scanf("%d%d", &n, &p);
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> all;
	for (int i = 1; i <= n; ++i)
	{
		int t; scanf("%d", &t);
		all.emplace(t, i);
	}
	std::priority_queue<int,std::vector<int>,std::greater<int>> ready;
	std::queue<std::pair<long long,int>> q;
	while (!all.empty() || !q.empty())
	{
		long long t1 = all.empty() ? INF : all.top().first;
		long long t2 = q.empty() ? INF : q.front().first;
		if (t1 <= t2)
		{
			if (q.empty())
				q.emplace(all.top().first + p, all.top().second);
			else if (all.top().second < q.back().second)
				q.emplace(q.back().first + p, all.top().second);
			else 
				ready.push(all.top().second);
			all.pop();
		}
		else 
		{
			ans[q.front().second] = t2;
			q.pop();
			if (q.empty() && !ready.empty())
			{
				q.emplace(t2 + p, ready.top());
				ready.pop();
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	printf("\n");
}