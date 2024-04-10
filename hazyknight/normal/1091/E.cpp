#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 500005;

int n,p,L,R;
int a[MAXN];
int b[MAXN];

int check(int deg)
{
	int pos;
	for (int i = 1;i <= n + 1;i++)
	{
		if (a[i] > deg)
			b[i] = a[i];
		else
		{
			b[i] = deg,pos = i;
			for (int j = i;j <= n;j++)
				b[j + 1] = a[j];
			break;
		}
	}
	ll pref = 0,suf = 0;
	for (int k = 1,j = n + 1;k <= n + 1;k++)
	{
		pref += b[k];
		while (j >= k && b[j] <= k)
			suf += b[j],j--;
		while (j < k)
			suf -= b[j + 1],j++;
		ll val = pref - (ll)k * (k - 1) - (ll)k * (j - k) - suf;
		if (val > 0)
			return pos <= k ? 1 : -1;
	}
	return 0;
}

int calcl()
{
	int low = 0,high = n;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (check(2 * mid + p) == -1)
			low = mid + 1;
		else
			high = mid;
	}
	if (check(2 * low + p) != 0)
	{
		cout << -1 << endl;
		exit(0);	
	}
	return low;
}

int calcr()
{
	int low = 0,high = n;
	while (low < high)
	{
		int mid = (low + high + 1) >> 1;
		if (check(2 * mid + p) == 1)
			high = mid - 1;
		else
			low = mid;
	}
	return low;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i],p ^= (a[i] & 1);
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	L = calcl();
	R = calcr();
	for (int i = L;i <= R;i++)
		cout << 2 * i + p << ' ';
	cout << endl;
	return 0;
}