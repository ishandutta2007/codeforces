#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAXN = 2005;

int T,n,m,MAX;

pair<pair<int,int>,pair<int,int> > ans[26];

vector<pair<int,int> > pos[26];

char s[MAXN][MAXN];

bool cmpx(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.second < b.second;
}

bool cmpy(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first < b.first;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			scanf("%s",s[i] + 1);
		for (int i = 0;i < 26;i++)
			pos[i].clear();
		MAX = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (s[i][j] != '.')
				{
					MAX = max(MAX,s[i][j] - 'a' + 1);
					pos[s[i][j] - 'a'].push_back(make_pair(i,j));
				}
		int exx = 0,exy = 0;
		bool ok = 1;
		for (int i = MAX - 1;i >= 0;i--)
		{
			if (!pos[i].size())
			{
				ans[i] = make_pair(make_pair(exx,exy),make_pair(exx,exy));
				continue;
			}
			bool okx = 1,oky = 1;
			for (int j = 0;j < pos[i].size() - 1;j++)
			{
				if (pos[i][j].first != pos[i][j + 1].first)
					okx = 0;
				if (pos[i][j].second != pos[i][j + 1].second)
					oky = 0;
			}
			if (!okx && !oky)
			{
				ok = 0;
				break;
			}
			if (okx)
			{
				sort(pos[i].begin(),pos[i].end(),cmpx);
				int X = pos[i][0].first,Y1 = pos[i][0].second,Y2 = pos[i].back().second;
				for (int j = Y1;j <= Y2;j++)
					if (s[X][j] != char(i + 'a') && s[X][j] != '#')
					{
						ok = 0;
						break;
					}
				if (!ok)
					break;
				ans[i] = make_pair(make_pair(X,Y1),make_pair(X,Y2));
				for (int j = Y1;j <= Y2;j++)
				{
					exx = X;
					exy = j;
					s[X][j] = '#';
				}
			}
			else
			{
				sort(pos[i].begin(),pos[i].end(),cmpy);
				int Y = pos[i][0].second,X1 = pos[i][0].first,X2 = pos[i].back().first;
				for (int j = X1;j <= X2;j++)
					if (s[j][Y] != char(i + 'a') && s[j][Y] != '#')
					{
						ok = 0;
						break;
					}
				if (!ok)
					break;
				ans[i] = make_pair(make_pair(X1,Y),make_pair(X2,Y));
				for (int j = X1;j <= X2;j++)
				{
					exx = j;
					exy = Y;
					s[j][Y] = '#';
				}
			}
		}
		if (!ok)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%d\n",MAX);
		for (int i = 0;i < MAX;i++)
			printf("%d %d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second.first,ans[i].second.second);
	}
	return 0;
}