#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,c1,c2,v,q;
int s[100005];
int e[100005];

long long ans;

int bs1(int *arr,int l,int v)
{
	if (!l)
		return -1;
	if (arr[1] > v)
		return -1;
	int low = 1,high = l;
	while (low < high)
	{
		int mid = (low + high + 1) >> 1;
		if (arr[mid] <= v)
			low = mid;
		else
			high = mid - 1; 
	}
	return arr[low];
}

int bs2(int *arr,int l,int v)
{
	if (!l)
		return -1;
	if (arr[l] < v)
		return -1;
	int low = 1,high = l;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (arr[mid] >= v)
			high = mid;
		else
			low = mid + 1;
	}
	return arr[low];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> c1 >> c2 >> v;
	for (int i = 1;i <= c1;i++)
		cin >> s[i];
	for (int i = 1;i <= c2;i++)
		cin >> e[i];
	cin >> q;
	for (int i = 1;i <= q;i++)
	{
		long long xa,ya,xb,yb;
		cin >> ya >> xa >> yb >> xb;
		if (xa > xb)
			swap(xa,xb),swap(ya,yb);
		if (ya == yb)
		{
			cout << xb - xa << endl;
			continue;
		}
		int k = bs2(s,c1,xa);
		long long len = (1ll << 60) - 1;
		if (k != -1)
		{
			if (k > xb)
				len = abs(ya - yb) + (k - xb) * 2;
			else
				len = abs(ya - yb);
		}
		k = bs2(e,c2,xa);
		if (k != -1)
		{
			if (k > xb)
				len = min(len,(abs(ya - yb) - 1) / v + 1 + (k - xb) * 2);
			else
				len = min(len,(abs(ya - yb) - 1) / v + 1);
		}
		k = bs1(s,c1,xb);
		if (k != -1)
		{
			if (k < xa)
				len = min(len,abs(ya - yb) + (xa - k) * 2);
			else
				len = min(len,abs(ya - yb));
		}
		k = bs1(e,c2,xb);
		if (k != -1)
		{
			if (k < xa)
				len = min(len,(abs(ya - yb) - 1) / v + 1 + (xa - k) * 2);
			else
				len = min(len,(abs(ya - yb) - 1) / v + 1);
		}
		cout << len + xb - xa << endl;
	}
	return 0;
}