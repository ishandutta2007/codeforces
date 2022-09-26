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
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
int a[MAXN];
int nxt[MAXN];

ll T,SUM,ans;
ll sum[MAXN];

void add(int p,int x)
{
	if (!p)
		return;
	while (p <= n)
	{
		sum[p] += x;
		p += (p & -p);
	}
}

ll query(int p)
{
	ll ret = 0;
	while (p >= 1)
	{
		ret += sum[p];
		p -= (p & -p);
	}
	return ret;
}

int getnxt(int p)
{
	return p == nxt[p] ? p : nxt[p] = getnxt(nxt[p]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> T;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		SUM += a[i];
		add(i,a[i]);
	}
	for (int i = 1;i <= n;i++)
		nxt[i] = i;
	for (int i = 1;i <= n;i++)
	{
		ans += (T / SUM) * (n - i + 1);
		T %= SUM;
		int low = 0,high = n;
		while (low < high)
		{
			int mid = (low + high + 1) >> 1;
			if (query(mid) <= T)
				low = mid;
			else
				high = mid - 1;
		}
		int pos = getnxt(low + 1);
		SUM -= a[pos];
		add(pos,-a[pos]);
		nxt[pos] = nxt[pos + 1];
	}
	cout << ans << endl;
	return 0;
}