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

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
int fa[MAXN];
int ans[MAXN];

ll a[MAXN];
ll sum[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void modify(int p,int v)
{
	while (p <= n)
	{
		sum[p] += v;
		p += p & -p;
	}
}

ll query(int p)
{
	ll res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

int main()
{
	srand(time(0));
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		modify(i,i);
		fa[i] = i;
	}
	for (int i = n;i >= 1;i--)
	{
		int low = 1,high = n;
		while (low < high)
		{
			int mid = low + high >> 1;
			if (!getroot(mid) || query(getroot(mid) - 1) < a[i])
				low = mid + 1;
			else
				high = mid;
		}
		fa[low] = low - 1;
		modify(low,-low);
		ans[i] = low;
	}
	for (int i = 1;i <= n;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}