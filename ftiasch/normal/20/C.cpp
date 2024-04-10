// Codeforces Beta Round #20
// Problem C -- Dijkstra?
#include <queue>
#include <cstdio>
#include <utility>
#include <iostream>
#include <algorithm>

#define N 100001
#define M 200001
#define INF 1000000000000LL

using namespace std;

int n, m, v[N], a[M], b[M], c[M], p[M], q[M];
long long d[N];
priority_queue<pair<long long, int> > heap;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i)
		v[i] = 0;
	for(int i = 1; i <= m; ++ i)
	{
		// a_i -> b_i
		scanf("%d%d%d", a + i, b + i, c + i);
		p[i] = v[a[i]];
		v[a[i]] = i;
		// b_i -> a_i
		a[i + m] = b[i];
		b[i + m] = a[i];
		c[i + m] = c[i];
		p[i + m] = v[a[i + m]];
		v[a[i + m]] = i + m;
	}
	for(int i = 1; i <= n; ++ i)
		d[i] = INF;
	d[n] = 0;
	heap.push(make_pair(0, n));
	while(!heap.empty())
	{
		pair<long long, int> temp = heap.top();
		heap.pop();
		if(-temp.first > d[temp.second])
			continue;
		for(int i = v[temp.second]; i; i = p[i])
			if(d[a[i]] + c[i] < d[b[i]])
			{
				d[b[i]] = d[a[i]] + c[i];
				q[b[i]] = a[i];
				heap.push(make_pair(-d[b[i]], b[i]));
			}
	}
	if(d[1] == INF)
		printf("-1\n");
	else
	{
		for(int i = 1; i != n; )
			printf("%d ", i), i = q[i];
		printf("%d\n", n);
	}
	return 0;
}