#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1e9 + 7;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int aa = a[0];
		for (int i = 0; i < n; i++) aa &= a[i];
		int cnt = count(a.begin(), a.end(), aa);
		ll ans = (cnt * 1ll * (cnt - 1));
		for (int i = 1; i <= n - 2; i++) ans = (ans * 1ll * i) % mod;
		cout << ans << "\n";
	}
	return 0;
}