#include <bits/stdc++.h>
using namespace std;

int n, a[100100], pos[100100], isPrime[100100], done[300300];
vector <int> primes, sums[300300];
vector < pair<int,int> > ans;

void doSwap(int x, int y)
{
	int len = x - y + 1;
	
	for (int i = 0; i < int(sums[len].size()); i++)
	{
		int u = sums[len][i];
		y = x - u + 1;
		swap(a[x], a[y]);
		pos[a[x]] = x;
		pos[a[y]] = y;
		ans.push_back(make_pair(y, x));
		x = y;
	}
}

void init()
{
	for (int i = 2; i <= 100000; i++)
	{
		isPrime[i] = 1;
		for (int j = 2; j * j <= i && isPrime[i]; j++)
			if (i % j == 0) isPrime[i] = 0;
		if (isPrime[i]) primes.push_back(i);
	}
	
	int P = primes.size();
	
	for (int i = 0; i < P; i++)
	{
		if (!done[primes[i]])
		{
			done[primes[i]] = 1;
			sums[primes[i]].push_back(primes[i]);
		}
		
		for (int j = i; j < P; j++) 
			if (!done[primes[i] + primes[j] - 1])
			{
				done[primes[i] + primes[j] - 1] = 1;
				sums[primes[i] + primes[j] - 1].push_back(primes[i]);
				sums[primes[i] + primes[j] - 1].push_back(primes[j]);
			}
	}
	
	for (int i = 2; i <= 100000; i++)
		if (!done[i]) 
		{
			for (int j = 0; j < P && !done[i]; j++)
				for (int k = j; k < P && primes[j] + primes[k] < i; k++)
					if (isPrime[i + 2 - primes[j] - primes[k]])
					{
						sums[i].push_back(primes[j]);
						sums[i].push_back(primes[k]);
						sums[i].push_back(i + 2 - primes[j] - primes[k]);
						done[i] = 1;
						break;
					}
		}
}

int main()
{
	ios::sync_with_stdio(0);
	init();
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
	
	for (int x = 1; x < n; x++)
		if (pos[x] != x)
			doSwap(pos[x], x);
			
	cout << ans.size() << endl;
	for (int i = 0; i < int(ans.size()); i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
}