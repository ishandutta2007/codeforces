#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int d[10010];

int main()
{
	set <int> s;
	int m, n, x, k;
	cin >> m >> n >> k;
	n *= m;
	for (int i = 0; i < n; i++) 
	{
		cin >> x; 
		d[x / k]++;
		s.insert(x % k);
	}
	
	if (s.size() > 1) cout << -1 << endl;
	else
	{
		int cur = 0, onLeft = 0;
		for (int i = 0; i <= 10000; i++) cur += d[i] * i;
		int ans = cur;
		for (int i = 1; i <= 10000; i++)
		{
			onLeft += d[i - 1];
			cur += onLeft - (n - onLeft);
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}
}