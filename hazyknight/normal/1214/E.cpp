#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

int n,d;
int a[MAXN];

vector<int> q[MAXN];
vector<int> att[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&d);
		q[d].push_back(i);
	}
	int len = n,cur = n;
	for (int i = 1;i <= n;i++)
	{
		int ext = len - i + 1;
		if (q[ext].size())
		{
			int u = q[ext].back();
			q[ext].pop_back();
			a[i] = u * 2 - 1;
			a[++len] = u * 2;
			continue;
		}
		while (!q[cur].size())
			cur--;
		int u = q[cur].back();
		q[cur].pop_back();
		a[i] = u * 2 - 1;
		att[i + cur - 1].push_back(u * 2);
	}
	for (int i = 1;i < len;i++)
		printf("%d %d\n",a[i],a[i + 1]);
	for (int i = 1;i <= len;i++)
		for (int j = 0;j < att[i].size();j++)
			printf("%d %d\n",a[i],att[i][j]);
	return 0;
}