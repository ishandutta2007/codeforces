#include <bits/stdc++.h>
using namespace std;
const double oo = 1e15, EPS = 1e-8, PI = acos(-1.0);

double f[1 << 20], x[20], y[20], angle[20], L, R;
int n;

double calc(double x0, double x1, double y1, double alpha)
{
	double theta = atan2(-y1, x0 - x1);
	theta += alpha;
	if (theta > -EPS) return R;
	return min(R, x1 - y1 / tan(theta));
}

double dp(int mask)
{
	if (f[mask] > -0.5) return f[mask];
	f[mask] = 0;
	
	for (int i = 0; i < n; i++)
		if (mask >> i & 1)
		{
			double rightmost = dp(mask ^ 1 << i);
			f[mask] = max(f[mask], calc(rightmost, x[i], y[i], angle[i]));
		}
		
	return f[mask];
}

int main()
{
	cin >> n >> L >> R;
	R -= L;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> angle[i];
		angle[i] = angle[i] * PI / 180;
		x[i] -= L;
	}
	
	memset(f, -1, sizeof f);
	printf("%.9lf\n", dp((1 << n) - 1));
}