#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int n,k;
int cnt1[100005];
int cnt2[100005];

long long ans;
long long h[15];
long long f[505][5005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int v,i = 1;i <= n * k;i++)
	{
		cin >> v;
		cnt1[v]++;
	}
	for (int v,i = 1;i <= n;i++)
	{
		cin >> v;
		cnt2[v]++;
	}
	for (int i = 1;i <= k;i++)
		cin >> h[i];
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= n * k;j++)
			for (int l = 0;l <= min(j,k);l++)
				f[i][j] = max(f[i][j],f[i - 1][j - l] + h[l]);
	for (int i = 1;i <= 100000;i++)
		ans += f[cnt2[i]][cnt1[i]];
	cout << ans << endl;
	return 0;
}