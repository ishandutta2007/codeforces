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
#include <bitset>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

ll n,q,l,r;
ll s[MAXN];
ll d[MAXN];
ll sum[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> s[i];
	sort(s + 1,s + n + 1);
	for (int i = 1;i < n;i++)
		d[i] = s[i + 1] - s[i];
	sort(d + 1,d + n);
	for (int i = n - 1;i >= 1;i--)
		sum[i] = sum[i + 1] + d[i];
	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		ll MIN = s[1] + l,MAX = s[n] + r;
		if (d[n - 1] <= r - l + 1)
		{
			cout << MAX - MIN + 1 << endl;
			continue;
		}
		int low = 1,high = n - 1;
		while (low < high)
		{
			int mid = low + high >> 1;
			if (d[mid] > r - l + 1)
				high = mid;
			else
				low = mid + 1;
		}
		cout << MAX - MIN + 1 - sum[low] + (n - low) * (r - l + 1) << ' ';
	}
	cout << endl;
	return 0;
}