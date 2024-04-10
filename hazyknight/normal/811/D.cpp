#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

int n,m;
int x,y;

char map[105][105];
string path[105][105];

bool isswap[2];

void put(char c)
{
	if (isswap[0])
	{
		if (c == 'L')
			c = 'R';
		else if (c == 'R')
			c = 'L';
	}
	if (isswap[1])
	{
		if (c == 'U')
			c = 'D';
		else if (c == 'D')
			c = 'U';
	}
	cout << c << endl;
}

queue<pair<int,int> > Q;

string npath;

void update(int xa,int ya,char t)
{
	if (xa < 1 || xa > n || ya < 1 || ya > m || map[xa][ya] == '*' || path[xa][ya].size())
		return;
	path[xa][ya] = npath + t;
	Q.push(make_pair(xa,ya));
}

void bfs()
{
	Q.push(make_pair(x,y));
	while (!Q.empty())
	{
		pair<int,int> now = Q.front();
		npath = path[now.first][now.second];
		Q.pop();
		update(now.first - 1,now.second,'U');
		update(now.first + 1,now.second,'D');
		update(now.first,now.second - 1,'L');
		update(now.first,now.second + 1,'R');
	}
}

int main()
{
	cin >> n >> m;
	getchar();
	for (int i = 1;i <= n;i++,getchar())
		for (int j = 1;j <= m;j++)
			map[i][j] = getchar();
	if (map[1][2] != '*')
	{
		cout << "R" << endl;
		cin >> x >> y;
		if (y == 1)
			isswap[0] = true;
		if (y == 2)
		{
			put('L');
			cin >> x >> y;
		}
		for (int i = 1;i <= m;i++)
		{
			if (map[2][i] != '*')
				break;
			put('R');
			cin >> x >> y;
		}
		cout << "D" << endl;
		cin >> x >> y;
		if (x == 1)
			isswap[1] = true;
	}
	else
	{
		cout << "D" << endl;
		cin >> x >> y;
		if (x == 1)
			isswap[1] = true;
		if (x == 2)
		{
			put('U');
			cin >> x >> y;
		}
		for (int i = 1;i <= n;i++)
		{
			if (map[i][2] != '*')
				break;
			put('D');
			cin >> x >> y;
		}
		cout << "R" << endl;
		cin >> x >> y;
		if (y == 1)
			isswap[0] = true;
	}
	bfs();
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (map[i][j] == 'F')
			{
				for (int k = 0;k < path[i][j].size();k++)
				{
					put(path[i][j][k]);
					cin >> x >> y;
				}
			}
	fflush(stdout);
	return 0;
}