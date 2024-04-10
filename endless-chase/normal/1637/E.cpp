#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, m, a[333333], id[333333], cnt, arr[333333], all, ct[333333], num[333333], x, y, pos;
vector<int> brr[3333];
vector<int> v[333333];
map<int, int> mp;
long long ans;
bool u[333333];
int fnd(int x)
{
	return lower_bound(arr + 1, arr + all + 1, x) - arr;
}
bool cmp(int x, int y)
{
	return arr[x] > arr[y];
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		mp.clear();
		for (int i = 1; i <= n; i++) arr[i] = a[i];
		sort(arr + 1, arr + n + 1);
		all = unique(arr + 1, arr + n + 1) - arr - 1;
		for (int i = 1; i <= n; i++) a[i] = fnd(a[i]);
		for (int i = 1; i <= all; i++) ct[i] = 0;
		for (int i = 1; i <= n; i++) ct[a[i]]++;
		cnt = 0;
		for (int i = 1; i <= n; i++) id[i] = 0;
		for (int i = 1; i <= all; i++)
		{
			if (!id[ct[i]])
			{
				id[ct[i]] = ++cnt;
				num[cnt] = ct[i];
			}
		}
		for (int i = 1; i <= cnt; i++) brr[i].clear();
		for (int i = 1; i <= all; i++) brr[id[ct[i]]].push_back(i);
		for (int i = 1; i <= cnt; i++) sort(brr[i].begin(), brr[i].end(), cmp);
		for (int i = 1; i <= all; i++) v[i].clear();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			x = fnd(x); y = fnd(y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ans = 0;
		for (int i = 1; i <= all; i++)
		{
			u[i] = 1;
			for (int j = 0; j < v[i].size(); j++)
			{
				u[v[i][j]] = 1;
			}
			for (int j = 1; j <= cnt; j++)
			{
				pos = 0;
				while(pos < brr[j].size() && u[brr[j][pos]]) pos++;
				if (pos < brr[j].size()) 
				{
					ans = max(ans, 1ll * (ct[i] + num[j]) * (arr[i] + arr[brr[j][pos]]));	
				//	if (1ll * (ct[i] + num[j]) * (arr[i] + arr[brr[j][pos]]) == 48) cout << arr[i] << " " << arr[brr[j][pos]] << endl;
				}
			}
			u[i] = 0;
			for (int j = 0; j < v[i].size(); j++)
			{
				u[v[i][j]] = 0;
			}
		}
		printf("%lld\n", ans);
	}
	return Accepted;
}