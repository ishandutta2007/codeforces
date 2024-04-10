#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int n, flag[5555], delX, delY, node[5555];
long long dist[5555], sumDist[5555], distInside;
vector <int> a[5555], c[5555];

void visit(int x, int _flag)
{
	long long sumChild = 0;
	flag[x] = _flag;
	sumDist[x] = dist[x];
	node[x] = 0;
	
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (flag[y]) continue;
		if ((x == delX && y == delY) || (x == delY && y == delX)) continue;
		
		dist[y] = dist[x] + c[x][i];
		visit(y, _flag);
		
		long long curSumChild = sumDist[y] - dist[x] * node[y];
		distInside += curSumChild * node[x] + sumChild * node[y];
		sumChild += curSumChild;
		node[x] += node[y];
		sumDist[x] += sumDist[y];
	}
	node[x]++;
	distInside += sumDist[x] - dist[x] * node[x];
}

void calc(int x, int par, int total)
{
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (flag[y] != flag[x] || y == par) continue;
		sumDist[y] = sumDist[x] + (total - 2LL * node[y]) * c[x][i];
		calc(y, x, total);
	}
}

int main()
{
	//freopen("e.in", "r", stdin);
	int x, y, z;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y >> z;
		a[x].push_back(y); c[x].push_back(z);
		a[y].push_back(x); c[y].push_back(z);
	}
	
	long long ans = 1LL << 60;
	for (int x = 1; x <= n; x++)
		for (int i = 0; i < int(a[x].size()); i++)
		{
			int y = a[x][i], len = c[x][i];
			if (y < x) continue;
			memset(flag, 0, sizeof(flag));
			delX = x; delY = y;
			
			distInside = 0;
			
			dist[x] = 0; 
			visit(x, 1); 
			calc(x, 0, node[x]);
			
			dist[y] = 0; 
			visit(y, 2); 
			calc(y, 0, node[y]);
			
			long long bestX = 1LL << 60, bestY = bestX;
			for (int i = 1; i <= n; i++)
				if (flag[i] == 1) bestX = min(bestX, sumDist[i]);
				else bestY = min(bestY, sumDist[i]);
				
			long long res = distInside + bestX * node[y] + bestY * node[x] + 1LL * len * node[x] * node[y];
			ans = min(ans, res);
		}
		
	cout << ans << endl;
}