#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, enemy[300300], color[300300], inQueue[300300];
vector <int> a[300300];

int main()
{
	int m, x, y;
	cin >> n >> m;
	while (m--) 
	{
		scanf("%d%d", &x, &y); 
		a[x].push_back(y); enemy[x]++;
		a[y].push_back(x); enemy[y]++;
	}
	
	queue <int> q;
	for (int i = 1; i <= n; i++)
		if (enemy[i] > 1) q.push(i), inQueue[i] = 1;
		
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		inQueue[x] = 0;
		if (enemy[x] < 2) continue;
		
		color[x] ^= 1; 
		enemy[x] = a[x].size() - enemy[x];
		
		for (int i = 0; i < int(a[x].size()); i++)
		{
			int y = a[x][i];
			if (color[y] != color[x]) enemy[y]--;
			else 
				if (++enemy[y] > 1 && !inQueue[y]) q.push(y), inQueue[y] = 1;
		}
	}
	
	for (int i = 1; i <= n; i++) cout << color[i];
	puts("");
}