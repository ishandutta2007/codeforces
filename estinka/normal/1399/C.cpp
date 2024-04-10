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
//#pragma optimize GCC("O3")
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll>w(n);
		vector<ll>f(2*n+1);
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			f[w[i]]++;
		}
		ll odpoved = 0;
		for (int s = 0; s <= 2 * n; s++)
		{
			ll ans = 0;
			vector<ll>cf = f;
			for (int i = 0; i < n; i++)
			{
				if (s < w[i]) continue;
				if (w[i] == s - w[i] && f[w[i]] > 1)
				{
					f[s - w[i]]--;
					f[w[i]]--;
					ans++;
				}
				else if (w[i] != s - w[i] && f[s - w[i]] && f[w[i]])
				{
					f[s - w[i]]--;
					f[w[i]]--;
					ans++;
				}
			}
			odpoved = max(odpoved, ans);
			f = cf;
		}
		cout << odpoved << endl;
	}
	return 0;
}