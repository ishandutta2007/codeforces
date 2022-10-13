#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <utility>
using namespace std;

struct problem
{
	int timeSmall, timeLarge;
	double failProb;
	long long scoreSmall, scoreLarge;
	
	void read()
	{
		cin >> scoreSmall >> scoreLarge >> timeSmall >> timeLarge >> failProb;
		scoreSmall *= 1000000;
		scoreLarge *= (1000000 - int(failProb * 1000000 + 0.5));
	}
	
	bool operator < (problem u) const
	{
		return timeLarge * failProb * (1 - u.failProb) < u.timeLarge * u.failProb * (1 - failProb);
	}
} a[1010];

int n, T;
pair <long long,double> f[1600];

int main()
{
	cin >> n >> T;
	for (int i = 0; i < n; i++) a[i].read();
	sort(a, a + n);
	
	for (int j = 1; j <= T; j++) f[j] = make_pair(-1, 0);
	
	for (int i = 0; i < n; i++)
		for (int j = T; j >= 0; j--)
		{
			int jj = j + a[i].timeSmall;
			if (jj > T) continue;
			long long score = f[j].first + a[i].scoreSmall;
			double penalty = -f[j].second + a[i].timeSmall;
			f[jj] = max(f[jj], make_pair(score, -penalty));
			
			jj += a[i].timeLarge;
			if (jj > T) continue;
			score += a[i].scoreLarge;
			penalty = penalty * a[i].failProb + jj * (1 - a[i].failProb);
			f[jj] = max(f[jj], make_pair(score, -penalty));
		}
			
	pair <long long,double> ans(-1, 0);
	for (int j = 0; j <= T; j++) ans = max(ans, f[j]);
	printf("%.9lf %.9lf\n", ans.first * 1e-6, -ans.second);
}