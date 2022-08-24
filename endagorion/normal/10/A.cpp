#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	int n, p1, p2, p3, t1, t2;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	int ans = 0;
	int l, r;
	cin >> l >> r;
	ans += p1 * (r - l);
	int time = r;
	for (int i = 1; i < n; ++i)
	{	
		cin >> l >> r;
		ans += p1 * (r - l);
		if (l - time < t1) ans += p1 * (l - time);
		else if (l - time < t1 + t2) ans += t1 * p1 + (l - time - t1) * p2;
		else ans += t1 * p1 + t2 * p2 + (l - time - t1 - t2) * p3;
		time = r;
	}	
	cout << ans << '\n';
	return 0;
}