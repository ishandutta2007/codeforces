#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int oo = int(1e9);

int n, a[555][555], order[555], f[555][555];
long long ans[555];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", a[i] + j);
			if (i != j) f[i][j] = oo;
		}
	
	for (int i = 1; i <= n; i++) scanf("%d", order + i);
	
	for (int i = n - 1; i; i--)
	{
		int x = order[i];
		for (int j = i + 1; j <= n; j++)
			for (int k = i + 1; k <= n; k++)
			{
				f[order[j]][order[i]] = min(f[order[j]][order[i]], f[order[j]][order[k]] + a[order[k]][order[i]]);
				f[order[i]][order[j]] = min(f[order[i]][order[j]], f[order[k]][order[j]] + a[order[i]][order[k]]);
			}
		for (int j = i; j <= n; j++)
			for (int k = i; k <= n; k++)
			{
				f[order[j]][order[k]] = min(f[order[j]][order[k]], f[order[j]][order[i]] + f[order[i]][order[k]]);
				ans[i] += f[order[j]][order[k]];
			}
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	puts("");
}