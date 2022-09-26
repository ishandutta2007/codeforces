#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

const int MAXN = 10005;

int n,q,x,y,ans;
int v[MAXN];
int cnt[MAXN];

bool ok[MAXN][MAXN];
bool global[MAXN];

pair<int,int> event[2][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1;i <= q;i++)
	{
		cin >> x >> y >> v[i];
		event[0][i] = make_pair(x,i);
		event[1][i] = make_pair(y + 1,i);
	}
	sort(event[0] + 1,event[0] + q + 1);
	sort(event[1] + 1,event[1] + q + 1);
	cnt[0] = 1;
	int j = 1,k = 1;
	for (int i = 1;i <= n;i++)
	{
		while (k <= q && event[1][k].first == i)
		{
			int id = event[1][k].second,V = v[id];
			for (int l = 0;l + V <= n;l++)
				if (cnt[l])
					cnt[l + V] -= cnt[l];
			k++;
		}
		while (j <= q && event[0][j].first == i)
		{
			int id = event[0][j].second,V = v[id];
			for (int l = n;l - V >= 0;l--)
				if (cnt[l - V])
				{
					cnt[l] += cnt[l - V];
					global[l] = true;
				}
			j++;
		}
	}
	for (int i = 1;i <= n;i++)
		if (global[i])
			ans++;
	cout << ans << endl;
	for (int i = 1;i <= n;i++)
		if (global[i])
			cout << i << ' ';
	cout << endl;
	return 0;
}