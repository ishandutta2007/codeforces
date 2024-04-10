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

const int MAXN = 5005;

int n,k;
int a[MAXN];

vector<int> cnt[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		cnt[a[i]].push_back(i);
	}
	int c = 1;
	for (int i = 1;i <= 5000;i++)
	{
		if (cnt[i].size() > k)
		{
			cout << "NO" << endl;
			return 0;
		}
		for (int j = 0;j < cnt[i].size();j++)
		{
			a[cnt[i][j]] = c;
			c = c % k + 1;
		}
	}
	cout << "YES" << endl;
	for (int i = 1;i <= n;i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}