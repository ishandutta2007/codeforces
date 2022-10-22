#include <iostream>

using namespace std;

long long l[5000], r[5000], m[5000], last, p;
int i, j, n, k;
long double dp[2000][2000];

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(12);

	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		for (p = 1; l[i] / p >= 10; p *= 10);
		if (l[i] /p == 1)
			last = l[i];
		else
			last = p * 2;
		for (; r[i] / p >= 10; p *= 10, last = p)
			m[i] += p * 2 - last;
		if (r[i] / p == 1)
			m[i] += r[i] - last + 1;
		else
			m[i] += p * 2 - last;
	}

	cin >> k;
	for (i = 0; i * 100 < k * n; ++i);
	k = i;
	dp[0][0] = 1;
	for (i = 1; i <= n; ++i)
		dp[0][i] = dp[0][i - 1] * (long double) (r[i] - l[i] + 1 - m[i]), dp[0][i] /= (long double) (r[i] - l[i] + 1);
	for (i = 1; i <= n; ++i)
		for (j = i; j <= n; ++j)
			dp[i][j] = dp[i][j - 1] * (long double) (r[j] - l[j] + 1 - m[j]) + dp[i - 1][j - 1] * (long double) m[j], 
			dp[i][j] /= (long double) (r[j] - l[j] + 1);

    for (i = n; i > k; --i)
		dp[k][n] += dp[i][n];

	cout << dp[k][n] << "\n";
}