#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int f[2020][44];

int main()
{
	int n, K, ans = 0;
	cin >> n >> K;
	
	for (int lastNumber = 1; lastNumber <= n; lastNumber++)
	{
		vector <int> divisors;
		for (int i = 1; i * i <= lastNumber; i++)
			if (lastNumber % i == 0)
			{
				divisors.push_back(i);
				if (i * i < lastNumber) divisors.push_back(lastNumber / i);
			}
			
		sort(divisors.begin(), divisors.end());
		int numDivisors = divisors.size();
		
		for (int i = 1; i <= K; i++)
			for (int j = 0; j < numDivisors; j++)
				f[i][j] = 0;
				
		vector <int> a[44];
		for (int i = 0; i < numDivisors; i++)
			for (int j = 0; j <= i; j++)
				if (divisors[i] % divisors[j] == 0)
					a[i].push_back(j);
		
		f[1][numDivisors - 1] = 1;
		for (int i = 1; i < K; i++)
			for (int j = 0; j < numDivisors; j++)
				for (int k = 0; k < int(a[j].size()); k++)
					f[i + 1][a[j][k]] = (f[i + 1][a[j][k]] + f[i][j]) % BASE;
						
		for (int j = 0; j < numDivisors; j++) ans = (ans + f[K][j]) % BASE;
	}
	
	cout << ans << endl;
}