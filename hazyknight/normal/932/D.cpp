#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

long long n;
long long weight[400005];
long long pre[400005][20];
long long last_ans;
long long sum[400005][20];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	long long cnt = 1;
	for (long long type,r,w,i = 1;i <= n;i++)
	{
		cin >> type >> r >> w;
		r ^= last_ans;
		w ^= last_ans;
		if (type == 1)
		{
			cnt++;
			weight[cnt] = w;
			long long &p = pre[cnt][0];
			if (weight[r] >= w)
				p = r;
			else
			{
				p = r;
				for (int j = 19;j >= 0;j--)
					if (pre[p][j] && weight[pre[p][j]] < weight[cnt])
						p = pre[p][j];
				p = pre[p][0];
			}
			sum[cnt][0] = weight[p];
			for (int j = 1;j <= 19;j++)
			{
				sum[cnt][j] = sum[cnt][j - 1] + sum[pre[cnt][j - 1]][j - 1];
				pre[cnt][j] = pre[pre[cnt][j - 1]][j - 1];
			}
		}
		else
		{
			if (weight[r] > w)
			{
				cout << (last_ans = 0) << endl;
				continue;
			}
			long long ans = 1;
			w -= weight[r];
			for (int j = 19;j >= 0;j--)
				if (pre[r][j] && sum[r][j] <= w)
					ans += (1 << j),w -= sum[r][j],r = pre[r][j];
			cout << (last_ans = ans) << endl;
		}
	}
	return 0;
}