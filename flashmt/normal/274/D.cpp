#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector <int> a[200200], order;
int N, n, color[200200], cyclic;

void visit(int x)
{
	color[x] = 1;
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (!color[y]) visit(y);
		else
			if (color[y] == 1) cyclic = 1;
	}
	if (x < n) order.push_back(x);
	color[x] = 2;
}

int main()
{
	int m, x;
	cin >> m >> n;
	N = n;
	while (m--)
	{
		vector < pair<int,int> > row;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &x);
			if (x >= 0) row.push_back(make_pair(x, j));
		}
		
		sort(row.begin(), row.end());
		int i = 0, R = row.size(), last = -1;
		while (1)
		{
			int j = i;
			while (j < R && row[j].first == row[i].first) 
			{
				if (last >= 0) a[last].push_back(row[j].second);
				j++;
			}
			
			if (j == R) break;
			
			last = N++;
			while (i < j) a[row[i++].second].push_back(last);
		}
	}
	
	for (int i = 0; i < n; i++) a[N].push_back(i);
	visit(N);
	
	if (cyclic) puts("-1");
	else
		for (int i = n - 1; i >= 0; i--) printf("%d ", order[i] + 1);
}