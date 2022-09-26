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

using namespace std;

const int MAXN = 100005;

int n,s;
int degree[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		degree[u]++;
		degree[v]++;
	}
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		if (degree[i] == 1)
			cnt++;
	cout << fixed << setprecision(7) << 2.0 * s / cnt << endl;
	return 0;
}