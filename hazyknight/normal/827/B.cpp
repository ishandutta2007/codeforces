#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

int n,k,MAX1,MAX2;
int dis[200005];
vector<pair<int,int> > ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 2;i <= k + 1;i++)
	{
		ans.push_back(make_pair(1,i));
		dis[i] = 1;
	}
	int j = 2,id = k + 2;
	while (id <= n)
	{
		dis[id] = dis[j] + 1;
		ans.push_back(make_pair(j,id));
		j++;
		id++;
	}
	cout << dis[n] + dis[n - 1] << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}