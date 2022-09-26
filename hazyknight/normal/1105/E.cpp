#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
#include <iomanip>
#include <bitset>

using namespace std;

int n,m,tp,tot;
int cur,ans;
int G[45][45];
int od[45];

bool mark[45];

string name;

set<int> S;
map<string,int> match;

int main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> tp;
		if (tp == 1)
		{
			for (set<int>::iterator i = S.begin();i != S.end();i++)
			{
				set<int>::iterator j = i;
				j++;
				for (;j != S.end();j++)
					G[*i][*j] = G[*j][*i] = true;
			}
			S.clear();
		}
		else
		{
			cin >> name;
			if (!match[name])
				match[name] = ++tot;
			S.insert(match[name]);
		}
	}
	for (set<int>::iterator i = S.begin();i != S.end();i++)
	{
		set<int>::iterator j = i;
		j++;
		for (;j != S.end();j++)
			G[*i][*j] = G[*j][*i] = true;
	}
	S.clear();
	for (int i = 1;i <= tot;i++)
		od[i] = i;
	for (int i = 1;i <= 100000;i++)
	{
		random_shuffle(od + 1,od + tot + 1);
		memset(mark,0,sizeof(mark));
		int cur = 0;
		for (int j = 1;j <= tot;j++)
			if (!mark[od[j]])
			{
				cur++;
				for (int k = 1;k <= tot;k++)
					if (G[od[j]][k])
						mark[k] = true;
			}
		ans = max(ans,cur);
	}
	cout << ans << endl;
	return 0;
}