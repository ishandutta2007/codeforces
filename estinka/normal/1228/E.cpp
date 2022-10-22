#ifdef __GNUG__
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <functional>
#endif
//#pragma optimize GCC("O3")
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1000000007;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	if (k == 1)
	{
		cout << "1\n";
		return 0;
	}
	vector<vector<ll> > nCk(n + 79, vector<ll>(n + 79, 0));
	vector<ll> mocniny_k(1, 1);
	for (int i = 0; i < n + 79; i++)
		mocniny_k.push_back((mocniny_k.back() * (k - 1)) % mod);
	nCk[0][0] = 1;
	for (int nn = 1; nn <= n; nn++)
	{
		for (int kk = 0; kk <= nn; kk++)
		{
			if (!kk)
			{
				nCk[nn][kk] = 1;
				continue;
			}
			nCk[nn][kk] = (nCk[nn - 1][kk] + nCk[nn - 1][kk - 1]) % mod;
		}
	}
	vector<vector<ll> > tabulka(n + 1, vector<ll>(n + 1, 0));
	for (int a = 0; a <= n; a++)
	{
		for (int x = a; x <= n; x++)
		{
			for (int i = 0; i <= a; i++)
			{
				tabulka[a][x] += (nCk[a][i] * mocniny_k[x - i]) % mod;
				tabulka[a][x] %= mod;
			}
		}
	}
	vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, 0));
	dp[0][0] = 1;
	for (int riadok = 1; riadok <= n; riadok++)
	{
		//cout << "=================== " << riadok << " ======================" << endl;
		for (int uz_pokryte = 0; uz_pokryte <= n; uz_pokryte++)
		{
			for (int nove = 0; nove + uz_pokryte <= n; nove++)
			{
				ll t = tabulka[uz_pokryte][n - nove];
				if (!nove)
					t = (mod + t - mocniny_k[n]) % mod;
				dp[riadok][uz_pokryte + nove] += (t * ((dp[riadok - 1][uz_pokryte] * nCk[n - uz_pokryte][nove]) % mod)) % mod;
				dp[riadok][uz_pokryte + nove] %= mod;
			}
		}
	}
	cout << dp[n][n] << "\n";
	return 0;
}