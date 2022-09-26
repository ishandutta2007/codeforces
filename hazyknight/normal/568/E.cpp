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
const int INF = 1e9 + 1;

int n,m,tot;
int a[MAXN];
int v[MAXN];
int f[MAXN];
int val[MAXN];
int pre[MAXN];
int sum[MAXN];
int cnt[MAXN];

pair<int,int> MAX[MAXN];
pair<int,int> tmp[MAXN];

inline pair<int,int> max(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first < b.first ? b : a;
}

int getval(int v)
{
	int low = 1,high = tot;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (val[mid] >= v)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}

void modify(int p,pair<int,int> v)
{
	while (p <= tot)
	{
		MAX[p] = max(MAX[p],v);
		p += p & -p;
	}
}

pair<int,int> query(int p)
{
	pair<int,int> r(0,0);
	while (p >= 1)
	{
		r = max(r,MAX[p]);
		p -= p & -p;
	}
	return r;
}

int main()
{
	scanf("%d",&n);
	a[1] = -INF;
	a[n + 2] = INF;
	val[++tot] = -INF;
	val[++tot] = INF;
	for (int i = 2;i <= n + 1;i++)
	{
		scanf("%d",&a[i]);
		if (~a[i])
			val[++tot] = a[i];
	}
	n += 2;
	scanf("%d",&m);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&v[i]);
		val[++tot] = v[i];
	}
	sort(v + 1,v + m + 1);
	sort(val + 1,val + tot + 1);
	tot = unique(val + 1,val + tot + 1) - val - 1;
	for (int i = 1;i <= n;i++)
		if (~a[i])
			a[i] = getval(a[i]);
	for (int i = 1;i <= m;i++)
	{
		v[i] = getval(v[i]);
		cnt[v[i]]++;
		sum[v[i]] = 1;
	}
	for (int i = 1;i <= tot;i++)
		sum[i] += sum[i - 1];
	for (int i = 1;i <= n;i++)
	{
	//	cout << "??" << a[i] << endl;
		if (~a[i])
		{
			pair<int,int> MX = query(a[i] - 1);
		//	cout << i << ' ' << MX.first << ',' << MX.second << endl;
			pre[i] = MX.second;
			modify(a[i],make_pair(f[i] = MX.first + 1,i));
		}
		else
		{
			for (int j = 1;j <= tot;j++)
				MAX[j] = max(MAX[j],MAX[j - (j & -j)]);
		//	for (int j = 1;j <= tot;j++)
		//		cout << MAX[j].first << ' ' << MAX[j].second << endl;
			for (int j = m;j >= 1;j--)
				MAX[v[j]] = max(MAX[v[j]],make_pair(MAX[v[j] - 1].first + 1,i));
			for (int j = 1;j <= tot;j++)
				if (j + (j & -j) <= tot)
					MAX[j + (j & -j)] = max(MAX[j + (j & -j)],MAX[j]);
		}
	}
//	for (int i = 1;i <= n;i++)
//		cout << f[i] << ',' << i << ' ';
//	cout << endl;
//	return 0;
	for (int i = 1;i <= tot;i++)
		MAX[i] = max(MAX[i],MAX[i - (i & -i)]);
	int p = n,ed = tot;
	while (p > 1)
	{
		if (~a[pre[p]])
			p = pre[p];
		else
		{
			int gap = 0;
			for (int i = p - 1;i >= 1;i--)
			{
				if (a[i] == -1)
				{
					gap++;
					continue;
				}
				if (a[i] >= a[p] || min(gap,sum[a[p] - 1] - sum[a[i]]) < f[p] - f[i] - 1)
					continue;
			//	cout << i << ' ' << f[p] - f[i] - 1 << ' ' << gap << ' ' << sum[a[p] - 1] - sum[a[i]] << endl;
				for (int j = p - 1;j > i;j--)
					if (a[j] == -1)
					{
						ed = min(ed,a[p] - 1);
						while (ed - 1 > a[i] && !cnt[ed])
							ed--;
						if (!cnt[ed])
							break;
						cnt[ed]--;
						a[j] = ed--;
					}
				p = i;
				break;
			}
		}
	//	cout << p << endl;
	}
	for (int i = 1,j = 1;i <= n;i++)
		if (a[i] == -1)
		{
			while (j + 1 <= tot && !cnt[j])
				j++;
			a[i] = j;
			cnt[j]--;
		}
	for (int i = 2;i < n;i++)
		printf("%d ",val[a[i]]);
	printf("\n");
	return 0;
}