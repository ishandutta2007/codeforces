#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n;
	double p[111];
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);
	
	double ans = p[n - 1], notAns = 1 - p[n - 1];
	for (int i = n - 2; i >= 0 && ans < notAns; i--)
	{
		ans = ans * (1 - p[i]) + notAns * p[i];
		notAns *= (1 - p[i]);
	}
	
	printf("%.12lf\n", ans);
}