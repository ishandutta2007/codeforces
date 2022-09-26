#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const int MX = 2500000;

int n;
int a[MAXN];

vector<int> cnt[MX + 5];
vector<pair<int,int> > C[MX * 2 + 5];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]].push_back(i);
	}
	for (int i = 1;i <= MX;i++)
		if (cnt[i].size() >= 4)
		{
			puts("YES");
			cout << cnt[i][0] << ' ' << cnt[i][1] << ' ' << cnt[i][2] << ' ' << cnt[i][3] << endl;
			return 0;
		}
	for (int i = 1;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
		{
			int sum = a[i] + a[j];
			C[sum].push_back(make_pair(i,j));
			for (int k = 0;k + 1 < C[sum].size();k++)
				if (C[sum][k].first != i && C[sum][k].second != i && C[sum][k].first != j && C[sum][k].second != j)
				{
					puts("YES");
					cout << C[sum][k].first << ' ' << C[sum][k].second << ' ' << i << ' ' << j << endl;
					return 0;
				}
		}
	puts("NO");
	return 0;
}