#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int n,m,ans;
int a[1505];
int b[1505];
int tmp[1505];

void merge(int l,int m,int r)
{
	int i,j,k;
	for (i = l,j = l,k = m;j < m && k < r;i++)
	{
		if (a[j] <= a[k])
			tmp[i] = a[j++];
		else
		{
			tmp[i] = a[k++];
			ans += m - j;
		}
	}
	while (j < m)
		tmp[i++] = a[j++];
	while (k < r)
		tmp[i++] = a[k++];
	for (int i = l;i < r;i++)
		a[i] = tmp[i];
}

void merge_sort(int l,int r)
{
	if (r - l <= 1)
		return ;
	int mid = (l + r) >> 1;
	merge_sort(l,mid);
	merge_sort(mid,r);
	merge(l,mid,r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> b[i];
	memcpy(a,b,sizeof(a));
	merge_sort(1,n + 1);
	ans = (ans & 1);
	cin >> m;
	for (int l,r,i = 1;i <= m;i++)
	{
		cin >> l >> r;
		if (((r - l + 1) * (r - l) / 2) & 1)
			ans ^= 1;
		cout << (ans ? "odd" : "even") << endl;	
	}
	return 0;
}