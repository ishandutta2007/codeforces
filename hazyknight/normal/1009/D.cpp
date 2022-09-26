#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 
#include <iomanip>

using namespace std;

int n,m,tot;
int phi[100005];
int prime[100005];

bool mark[100005];

int gcd(int a,int b)
{
	return b ? gcd(b,a % b) : a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if (m < n - 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	phi[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		if (!mark[i])
		{
			prime[++tot] = i;
			phi[i] = i - 1;
		}
		for (int j = 1;j <= tot && i * prime[j] <= n;j++)
		{
			mark[i * prime[j]] = true;
			if (i % prime[j] != 0)
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			else
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	phi[1] = 0;
	long long sum = 0;
	for (int i = 1;i <= n;i++)
		sum += phi[i];
	if (sum < m)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	for (int i = 2;i <= n;i++)
	{
		cout << 1 << ' ' << i << endl;
		m--;
	}
	for (int i = 2;i <= n;i++)
		for (int j = i + 1;j <= n;j++)
			if (gcd(i,j) == 1)
			{
				if (!m)
					return 0;
				cout << i << ' ' << j << endl;
				m--;
			}
	return 0;
}