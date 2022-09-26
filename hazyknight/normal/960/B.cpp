#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int n,k1,k2;
long long sum;
long long a[2000005];
long long b[2000005];

vector<int> pos[2000005];
vector<int> all;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k1 >> k2;
	k1 += k2;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		cin >> b[i];
	for (int i = 1;i <= n;i++)
	{
		pos[abs(a[i] - b[i])].push_back(i);
		sum += abs(a[i] - b[i]);
	}
	while (k1 > sum)
		k1 -= 2;
	if (k1 < 0)
		k1 += 2;
	all.clear();
	for (int i = 2000000;i >= 0;i--)
	{
		for (int j = 0;j < pos[i].size();j++)
			all.push_back(pos[i][j]);
		for (int j = 0;j < all.size();j++)
		{
			if (!k1)
				break;
			if (a[all[j]] < b[all[j]])
				a[all[j]]++;
			else
				b[all[j]]++;
			k1--;
		}
		if (!k1)
			break;
	}
	long long sum = 0;
	for (int i = 1;i <= n;i++)
		sum += (a[i] - b[i]) * (a[i] - b[i]);
	cout << sum << endl;
	return 0;
}