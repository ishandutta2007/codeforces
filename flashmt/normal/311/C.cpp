#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
const long long oo = 1LL << 60;

int value[100100], n, k, taken[100100];
long long dist[10010], H;
vector < pair<long long,int> > treasure[10010];
vector <long long> method;
priority_queue < pair<int,int> > reach;

void dijkstra()
{
	priority_queue < pair<long long,int> > q;
	
	for (int i = 1; i < k; i++) dist[i] = H;
	q.push(make_pair(0, 0));
	
	while (!q.empty())
	{
		int x = q.top().second; q.pop();
		
		for (int i = 0; i < int(method.size()); i++)
		{
			long long D = dist[x] + method[i];
			int y = D % k;
			if (dist[y] <= D) continue;
			dist[y] = D;
			q.push(make_pair(-D, y));
		}
	}
	
	for (int i = 1; i < k; i++)
		while (!treasure[i].empty())
		{
			pair <long long,int> u = treasure[i].back();
			if (u.first < dist[i]) break;
			reach.push(make_pair(value[u.second], -u.second));
			treasure[i].pop_back();
		}
}

int query()
{
	while (!reach.empty())
	{
		int i = -reach.top().second, V = reach.top().first;
		reach.pop();
		if (taken[i]) continue;
		if (value[i] != V) reach.push(make_pair(value[i], -i));
		else
		{
			taken[i] = 1; 
			return V;
		}
	}
	return 0;
}

int main()
{
	int type, m, x, y;
	long long pos, step;
	
	cin >> H >> n >> m >> k;
	for (int i = 0; i < n; i++) 
	{
		scanf("%I64d%d", &pos, value + i);
		pos--;
		if (pos % k == 0) reach.push(make_pair(value[i], -i));
		else treasure[pos % k].push_back(make_pair(pos, i));
	}
	
	for (int i = 1; i < k; i++)
		sort(treasure[i].begin(), treasure[i].end());
		
	while (m--)
	{
		scanf("%d", &type);
		
		if (type == 1)
		{
			scanf("%I64d", &step);
			method.push_back(step);
			dijkstra();
		}
		
		if (type == 2)
		{
			scanf("%d%d", &x, &y);
			value[--x] -= y;
		}
		
		if (type == 3) printf("%d\n", query());
	}
}