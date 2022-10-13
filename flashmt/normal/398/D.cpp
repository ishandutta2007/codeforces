#include <bits/stdc++.h>
using namespace std;

int n, color[50500], threshold, isBig[50500], cnt[50500][2];
set <int> a[50500], b[50500];

void toggleColor(int x)
{
	if (isBig[x])
		for (set <int>::iterator it = b[x].begin(); it != b[x].end(); it++)
		{
			int y = *it;
			cnt[y][color[x]]--;
			cnt[y][color[x] ^ 1]++;
		}
	else
		for (set <int>::iterator it = a[x].begin(); it != a[x].end(); it++)
		{
			int y = *it;
			if (isBig[y])
			{
				cnt[y][color[x]]--;
				cnt[y][color[x] ^ 1]++;
			}
		}
	color[x] ^= 1;
}

void removeEdge(int x, int y)
{
	a[x].erase(y);
	b[x].erase(y);
	isBig[x] = a[x].size() > threshold;
	if (isBig[x]) cnt[x][color[y]]--;
	
	a[y].erase(x);
	b[y].erase(x);
	isBig[y] = a[y].size() > threshold;
	if (isBig[y]) cnt[y][color[x]]--;
	
	if (!isBig[x]) 
	{
		for (set <int>::iterator it = b[x].begin(); it != b[x].end(); it++)
		{
			int u = *it;
			b[u].erase(x);
		}
		b[x].clear();
		cnt[x][0] = cnt[x][1] = 0;
	}
	
	if (!isBig[y])
	{
		for (set <int>::iterator it = b[y].begin(); it != b[y].end(); it++)
		{
			int u = *it;
			b[u].erase(y);
		}
		b[y].clear();
		cnt[y][0] = cnt[y][1] = 0;
	}
}

void addEdge(int x, int y)
{
	a[x].insert(y);
	isBig[x] = a[x].size() > threshold;
	if (isBig[x]) 
	{
		cnt[x][color[y]]++;
		if (isBig[y]) b[x].insert(y);
	}
	
	a[y].insert(x);
	isBig[y] = a[y].size() > threshold;
	if (isBig[y]) 
	{
		cnt[y][color[x]]++;
		if (isBig[x]) b[y].insert(x);
	}
	
	if (a[x].size() == threshold + 1)
	{
		cnt[x][0] = cnt[x][1] = 0;
		for (set <int>::iterator it = a[x].begin(); it != a[x].end(); it++)
		{
			int u = *it;
			cnt[x][color[u]]++;
			if (isBig[u]) b[x].insert(u), b[u].insert(x);
		}
	}
	
	if (a[y].size() == threshold + 1)
	{
		cnt[y][0] = cnt[y][1] = 0;
		for (set <int>::iterator it = a[y].begin(); it != a[y].end(); it++)
		{
			int u = *it;
			cnt[y][color[u]]++;
			if (isBig[u]) b[y].insert(u), b[u].insert(y);
		}
	}
}	

int main()
{
	ios::sync_with_stdio(0);
	//freopen("d.in", "r", stdin);
	
	int m, x, y, q, o;
	char type;
	cin >> n >> m >> q;
	
	cin >> o;
	while (o--) cin >> x, color[x] = 1;
	
	while (m--)
	{
		cin >> x >> y; 
		a[x].insert(y);
		a[y].insert(x);
	}

	for (threshold = 1; threshold * threshold <= n; threshold++);
	for (int x = 1; x <= n; x++) isBig[x] = a[x].size() > threshold;
	
	for (int x = 1; x <= n; x++)
		for (set <int>::iterator it = a[x].begin(); it != a[x].end(); it++)
		{
			int y = *it;
			if (isBig[x])
			{
				cnt[x][color[y]]++;
				if (isBig[y]) b[x].insert(y);
			}
		}
		
	while (q--)
	{
		cin >> type >> x;
		
		if (type == 'O' || type == 'F') toggleColor(x);
		
		if (type == 'A' || type == 'D')
		{
			cin >> y;
			if (type == 'A') addEdge(x, y);
			else removeEdge(x, y);
		}
		
		if (type == 'C')
		{
			if (isBig[x]) cout << cnt[x][1] << endl;
			else
			{
				int ans = 0;
				for (set <int>::iterator it = a[x].begin(); it != a[x].end(); it++)
					ans += color[*it];
				cout << ans << endl;
			}
		}
	}
}