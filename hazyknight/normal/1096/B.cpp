#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int n;

ll ans;

string s;

int main()
{
	cin >> n >> s;
	for (int i = 0;i < 26;i++)
	{
		int st = -1,ed = -1;
		for (int j = 0;j < n;j++)
			if (s[j] != 'a' + i)
			{
				st = j;
				break;
			}
		for (int j = n - 1;j >= 0;j--)
			if (s[j] != 'a' + i)
			{
				ed = j;
				break;
			}
		if (st == -1 && ed == -1)
			(ans += (ll)n * (n - 1) / 2 - 1) %= MOD;
		else
			(ans += (ll)(st + 1) * (n - ed) - 1) %= MOD;
	}
	cout << (ans + 1) % MOD << endl;
	return 0;
}