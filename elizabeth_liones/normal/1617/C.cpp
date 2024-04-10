#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> f(n + 1), f2(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] <= n)
			{
				f[a[i]]++;
			}
			else
			{
				f2[min(n, (a[i] - 1) / 2)]++;
			}
		}
		int ans = 0;
		int cnt = 0;
		for (int i = n; i >= 1; i--)
		{
			cnt += f2[i];
			if (f[i])
			{
				f[i]--;
			}
			else if (cnt)
			{
				cnt--;
				ans++;
			}
			else
			{
				ans = -1;
				break;
			}
			f2[(i - 1) / 2] += f[i];
		}
		cout << ans << "\n";
	}
	return 0;
}