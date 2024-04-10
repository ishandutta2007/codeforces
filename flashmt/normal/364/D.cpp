#include <bits/stdc++.h>
using namespace std;

int n, cnt[10100];
long long a[1000100], divisors[10100];

long long gcd(long long x, long long y)
{
	return x && y ? gcd(y, x % y) : x + y;
}

int main()
{
	ios::sync_with_stdio(0);
	srand(27081993);
	double t = clock();
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	random_shuffle(a, a + n);
		
	long long ans = 1;
	while ((clock() - t) / CLOCKS_PER_SEC < 3)
	{
		int id = rand() % n, numDivisors = 0;
		
		for (long long i = 1; i * i <= a[id]; i++)
			if (a[id] % i == 0) 
			{
				divisors[numDivisors++] = i;
				if (i * i < a[id]) divisors[numDivisors++] = a[id] / i;
			}
			
		sort(divisors, divisors + numDivisors);
		for (int i = 0; i <= numDivisors; i++) cnt[i] = 0;
		
		for (int i = 0; i < n; i++)
		{
			long long g = gcd(a[id], a[i]);
			int pos = lower_bound(divisors, divisors + numDivisors, g) - divisors;
			cnt[pos]++;
		}
		
		for (int i = numDivisors - 1; i >= 0; i--)
		{
			int sumCnt = cnt[i];
			for (int j = i + 1; j < numDivisors; j++)
				if (divisors[j] % divisors[i] == 0)
					sumCnt += cnt[j];
					
			if (sumCnt * 2 >= n) 
			{
				ans = max(ans, divisors[i]);
				break;
			}
		}
	}
	
	cout << ans << endl;
}