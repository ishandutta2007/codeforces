#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,m;
int a[10005];
int pos[10005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int l,r,x,i = 1;i <= m;i++)
	{
		cin >> l >> r >> x;
		int cnt = 0;
		for (int j = l;j <= r;j++)
			if (a[j] < a[x])
				cnt++;
		if (l + cnt == x)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}