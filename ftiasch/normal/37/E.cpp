// Codeforces Beta Round #37
// Problem E -- Trial for Chief
#include <list>
#include <cstdio>
#include <climits>
#include <utility>
#include <algorithm>

#define N 50

using namespace std;

int n, m, d[N][N];
char g[N][N + 1];

int work(int x_0, int y_0)
{
	int tmp = 0;
	for(int i = 0; i != n; ++ i)
		for(int j = 0; j != m; ++ j)
			d[i][j] = INT_MAX;
	d[x_0][y_0] = 0;
	list<pair<int, int> > q;
	q.clear();
	q.push_back(make_pair(x_0, y_0));
	while(!q.empty())
	{
		pair<int, int> s = q.front();
		if(g[s.first][s.second] == 'B')
			tmp = max(tmp, d[s.first][s.second]);
		q.pop_front();
		int d_x[4] = {-1, 0, 0, 1}, d_y[4] = {0, -1, 1, 0};
		for(int i = 0; i != 4; ++ i)
		{
			pair<int, int> t = make_pair(s.first + d_x[i], s.second + d_y[i]);
			if(t.first != -1 && t.first != n && t.second != -1 && t.second != m)
			{
				int w = g[s.first][s.second] != g[t.first][t.second];
				if(d[s.first][s.second] + w < d[t.first][t.second])
				{
					d[t.first][t.second] = d[s.first][s.second] + w;
					if(w)
						q.push_back(t);
					else
						q.push_front(t);
				}
			}
		}
	}
	return tmp;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i != n; ++ i)
		scanf("%s", g[i]);
	int ans = -1;
	for(int i = 0; i != n; ++ i)
		for(int j = 0; j != m; ++ j)
			ans += g[i][j] == 'B';
	for(int i = 0; i != n; ++ i)
		for(int j = 0; j != m; ++ j)
			ans = min(ans, work(i, j));
	printf("%d\n", ans + 1);
	return 0;
}