#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

bool is[maxn];

vector<int> primes;

int main()
{
	for(int i = 2; i < maxn; i++)
		if(!is[i])
		{
			primes.pb(i);
			for(ll j = 1LL * i * i; j < maxn; j += i)
				is[j] = 1;
		}
	int n , m , k;
	cin >> n >> m;
	k = lower_bound(primes.begin() , primes.end() , n) - primes.begin();
	k = primes[k];
	cout << k << " " << k << endl;
	m -= (n - 1);
	for(int i = 1; i < n - 1; i++)
		cout << i << " " << i + 1 << " " << 1 << endl;
	cout << n - 1 << " " << n << " " << k - n + 2 << endl;
	for(int i = 1; i <= n; i++)
		for(int j = i + 2; j <= n; j++)
		{
			if(!m)
				return 0;
			m--;
			cout << i << " " << j << " " << maxn * 200 << endl;
		}
}