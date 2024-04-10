#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int n;
long double T,ans,ans2;
pair<int,int> b[200005];
pair<long double,long double> a[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> T;
	for (int i = 1;i <= n;i++)
		cin >> b[i].second;
	for (int i = 1;i <= n;i++)
		cin >> b[i].first;
	sort(b + 1,b + n + 1);
	for (int i = 1;i <= n;i++)
	{
		a[i].first = b[i].first,a[i].second = b[i].second;
		ans += a[i].second;
		ans2 += a[i].first * a[i].second;
	}
	if (fabs(ans2 - T * ans) < 1e-6)
		cout << fixed << setprecision(8) << ans << endl;
	else
	{
		if (ans2 > T * ans)
		{
			int now = n;
			while (now >= 1 && ans2 > T * ans)
			{
				if (fabs(ans - a[now].second) < 1e-6 || ans2 - a[now].first * a[now].second <= T * (ans - a[now].second))
				{
					ans -= (T * ans - ans2) / (T - a[now].first);
					break;
				}
				ans2 -= a[now].first * a[now].second;
				ans -= a[now].second;
				now--;
			}
		}
		else
		{
			int now = 1;
			while (now <= n && ans2 < T * ans)
			{
				if (fabs(ans - a[now].second) < 1e-6 || ans2 - a[now].first * a[now].second >= T * (ans - a[now].second))
				{
					ans -= (T * ans - ans2) / (T - a[now].first);
					break;
				}
				ans2 -= a[now].first * a[now].second;
				ans -= a[now].second;
				now++;
			}
		}
		cout << fixed << setprecision(8) << ans << endl; 
	}
	return 0;
}