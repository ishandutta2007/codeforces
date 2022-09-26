#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int n,m;
char c[55][55];
int stx,sty;
int map[4],ans;

int main()
{
	cin >> n >> m;
	getchar();
	for (int i = 1;i <= n;i++,getchar())
		for (int j = 1;j <= m;j++)
		{
			c[i][j] = getchar();
			if (c[i][j] == 'S')
				stx = i,sty = j;
		}
	string s;
	cin >> s;
	for (int i = 0;i < 4;i++)
		map[i] = i;
	do
	{
		int nowx = stx,nowy = sty;
		bool ok = false;
		for (int i = 0;i < s.size();i++)
		{
			if (map[s[i] - '0'] == 0)
				nowx--;
			if (map[s[i] - '0'] == 1)
				nowx++;
			if (map[s[i] - '0'] == 2)
				nowy--;
			if (map[s[i] - '0'] == 3)
				nowy++;
			if (nowx < 1 || nowx > n || nowy < 1 || nowy > m)
				break;
			if (c[nowx][nowy] == '#')
				break;
			if (c[nowx][nowy] == 'E')
			{
				ok = true;
				break;
			}
		}
		if (ok)
			ans++;
	}
	while (next_permutation(map,map + 4));
	cout << ans << endl;
	return 0;
}