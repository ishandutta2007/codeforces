#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

const int MAXN = 2005;

int n,m,r,c,x,y,ans;
int MIN[MAXN][MAXN];

string s;

bool C[MAXN][MAXN];
bool mark[MAXN][MAXN];

priority_queue<pair<int,pair<int,int> > > Q;

void Dijkstra()
{
	Q.push(make_pair(0,make_pair(r,c)));
	MIN[r][c] = 0;
	while (!Q.empty())
	{
		int X = Q.top().second.first,Y = Q.top().second.second;
		int dis = -Q.top().first;
		Q.pop();
		if (mark[X][Y])
			continue;
		mark[X][Y] = true;
		if (X > 1 && C[X - 1][Y] && dis < MIN[X - 1][Y])
		{
			MIN[X - 1][Y] = dis;
			Q.push(make_pair(-dis,make_pair(X - 1,Y)));
		}
		if (X < n && C[X + 1][Y] && dis < MIN[X + 1][Y])
		{
			MIN[X + 1][Y] = dis;
			Q.push(make_pair(-dis,make_pair(X + 1,Y)));
		}
		if (Y > 1 && C[X][Y - 1] && dis + 1 < MIN[X][Y - 1])
		{
			MIN[X][Y - 1] = dis + 1;
			Q.push(make_pair(-dis - 1,make_pair(X,Y - 1)));
		}
		if (Y < m && C[X][Y + 1] && dis < MIN[X][Y + 1])
		{
			MIN[X][Y + 1] = dis;
			Q.push(make_pair(-dis,make_pair(X,Y + 1)));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> r >> c >> x >> y;
	for (int i = 1;i <= n;i++)
	{
		cin >> s;
		for (int j = 1;j <= m;j++)
		{
			C[i][j] = (s[j - 1] == '.');
			MIN[i][j] = (1 << 30) - 1;
		}
	}
	Dijkstra();
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (MIN[i][j] <= x && MIN[i][j] + j - c <= y)
				ans++;
	cout << ans << endl;
	return 0;
}