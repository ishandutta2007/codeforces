#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int n,a;
int cnt[3];
int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		cnt[a]++;
	}
	int cost = min(cnt[1],cnt[2]);
	ans += cost;
	cnt[1] -= cost;
	cnt[2] -= cost;
	ans += cnt[1] / 3;
	cout << ans << endl;
	return 0;
}