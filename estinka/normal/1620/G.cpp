#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

const int abc = 26, mod = 998244353, inf = 1e9 + 5;
void upd(int& a, int b) { a = (a + b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % ((ll)mod); }
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > f(n, vector<int>(abc, 0));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			f[i][s[j] - 'a']++;
		}
	}
	vector<int> cnt(1 << n, 1), mini(1 << n, 0);
	cnt[0] = 0;
	for (int i = 0; i < abc; i++)
	{
		mini[0] = inf;
		for (int j = 1; j < (1 << n); j++)
		{
			int lst = __builtin_ctz(j);
			mini[j] = min(mini[j ^ (1 << lst)], f[lst][i] + 1);
			cnt[j] = mul(cnt[j], mini[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < (1 << n); j++)
		{
			if (!(j & (1 << i)))
			{
				upd(cnt[j], mod - cnt[j ^ (1 << i)]);
			}
		}
	}
	int all = 0;
	vector<int> sum((1 << n), 0); // sucet tych, ktore lezia mimo masky i
	for (int j = 0; j < (1 << n); j++)
	{
		upd(all, cnt[j]);
		sum[j] = cnt[(1 << n) - 1 - j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if (j & (1 << i))
			{
				upd(sum[j ^ (1 << i)], sum[j]);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		ll val = add(all, mod - sum[i]);
		ll suma = 0, cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				suma += j + 1;
				cnt++;
			}
		}
		ans ^= val * cnt * suma;
	}
	cout << ans << "\n";
	return 0;
}