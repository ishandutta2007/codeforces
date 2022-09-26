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

typedef long long ll;

const int MAXN = 300005;

int T,n;
int v[MAXN];
int pos[MAXN];
int tmp[MAXN];

pair<int,int> a[MAXN];
pair<int,int> b[MAXN];

bool solve(int l,int r)
{
	if (l == r)
		return 1;
	int mid = l + r >> 1;
	if (!solve(l,mid))
		return 0;
	if (!solve(mid + 1,r))
		return 0;
	int MAX = 0,p = l,j = l;
	for (int i = mid + 1;i <= r;i++)
	{
		while (j <= mid && v[j] < v[i])
		{
			MAX = max(MAX,pos[v[j]]);
			tmp[p++] = v[j++];
		}
		if (pos[v[i]] < MAX)
			return 0;
		tmp[p++] = v[i];
	}
	while (j <= mid)
		tmp[p++] = v[j++];
	for (int i = l;i <= r;i++)
		v[i] = tmp[i];
	return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i].first);
			a[i].second = i;
		}
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&b[i].first);
			b[i].second = i;
		}
		sort(a + 1,a + n + 1);
		sort(b + 1,b + n + 1);
		bool ok = 1;
		for (int i = 1;i <= n;i++)
			if (a[i].first != b[i].first)
			{
				ok = 0;
				puts("NO");
				break;
			}
		if (!ok)
			continue;
		for (int i = 1;i <= n;i++)
		{
			a[i].first = i;
			swap(a[i].first,a[i].second);
		}
		for (int i = 1;i <= n;i++)
		{
			b[i].first = i;
			swap(b[i].first,b[i].second);
		}
		sort(a + 1,a + n + 1);
		sort(b + 1,b + n + 1);
		for (int i = 1;i <= n;i++)
			swap(a[i].first,a[i].second);
		for (int i = 1;i <= n;i++)
			swap(b[i].first,b[i].second);
		for (int i = 1;i <= n;i++)
			v[i] = a[i].first;
		for (int i = 1;i <= n;i++)
			pos[b[i].first] = i;
		puts(solve(1,n) ? "YES" : "NO");
	}
	return 0;
}