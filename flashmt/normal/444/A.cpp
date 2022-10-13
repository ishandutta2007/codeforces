#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n, m, x, y, z, v[555];
	cin >> n >> m;
	double ans = 0;
	for (int i = 1; i <= n; i++) cin >> v[i];
	while (m--)
	{
		cin >> x >> y >> z;
		ans = max(ans, 1.0 * (v[x] + v[y]) / z);
	}
	printf("%.12lf\n", ans);
}