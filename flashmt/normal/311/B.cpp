#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const long long oo = 1LL << 60;

struct hull
{
	long long A[100100], B[100100];
	double xLeft[100100];
	int head, tail;
	
	hull() {}
	
	void reset()
	{
		head = 1; tail = 0;
	}
	
	long long get(long long x)
	{
		while (head < tail && xLeft[head + 1] <= x) head++;
		xLeft[head] = x;
		return A[head] * x + B[head];
	}
	
	void add(long long AA, long long BB)
	{
		double x = 1e-18;
		while (tail >= head)
		{
			if (AA == A[tail]) return;
			x = 1.0 * (B[tail] - BB) / (AA - A[tail]);
			if (tail == head || x >= xLeft[tail]) break;
			tail--;
		}
		A[++tail] = AA; B[tail] = BB; xLeft[tail] = x;
	}
};

int n, m, p, d[100100];
long long s[100100], a[100100], f[105][100100];
hull h;

int main()
{
	int hill, t;
	cin >> n >> m >> p;
	for (int i = 2; i <= n; i++) scanf("%d", d + i), d[i] += d[i - 1];
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &hill, &t);
		a[i] = t - d[hill];
	}
	
	sort(a, a + m);
	for (int i = 0; i < m; i++) a[i] = a[m - 1] - a[i];
	reverse(a, a + m);
	for (int i = 1; i < m; i++) s[i] = s[i - 1] + a[i];
	for (int i = 0; i < m; i++) f[1][i] = s[i];
	
	for (int i = 2; i <= p; i++)
	{
		h.reset();
		h.add(-a[1], 0);
		for (int j = 1; j < m; j++)
		{
			f[i][j] = h.get(j) + s[j];
			if (j + 1 < m) h.add(-a[j + 1], a[j + 1] * j - s[j] + f[i - 1][j]);
		}
	}
	
	long long ans = oo;
	for (int i = 1; i <= p; i++) ans = min(ans, f[i][m - 1]);
	cout << ans << endl;
}