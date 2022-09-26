#include <bits/stdc++.h> 

using namespace std;

const int MAXN = 100005;

int n,fa,ans;
int depth[MAXN];
int cnt[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	cnt[0]++;
	for (int i = 2;i <= n;i++)
	{
		cin >> fa;
		depth[i] = depth[fa] + 1;
		cnt[depth[i]]++;
	}
	for (int i = 0;i < n;i++)
		ans += (cnt[i] & 1);
	cout << ans << endl;
	return 0;
}