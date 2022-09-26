#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int MAXN = 200005;

int n,m;
int b[MAXN];
int ans[MAXN];
int sum[MAXN];

pair<int,int> a[MAXN];
vector<pair<int,int> > q[MAXN];

void modify(int p)
{
	while (p <= n)
	{
		sum[p]++;
		p += p & -p;
	}
}

int query(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].first);
		b[i] = a[i].first;
		a[i].second = -i;
	}
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		a[i].second = -a[i].second;
	scanf("%d",&m);
	for (int k,pos,i = 1;i <= m;i++)
	{
		scanf("%d%d",&k,&pos);
		q[k].push_back(make_pair(pos,i));
	}
	for (int i = 1;i <= n;i++)
	{
		modify(a[i].second);
		for (int j = 0;j < q[i].size();j++)
		{
			int low = 1,high = n;
			while (low < high)
			{
				int mid = low + high >> 1;
				if (query(mid) < q[i][j].first)
					low = mid + 1;
				else
					high = mid;
			}
			ans[q[i][j].second] = b[low];
		}
	}
	for (int i = 1;i <= m;i++)
		printf("%d\n",ans[i]);
	return 0;
}