#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i] * b[i];
	ll ans = sum;
	for (int rl = 2; rl <= 2 * n; rl++)
	{
		vector<ll> s(n + 1, 0);
		for (int i = 1; i <= n; i++)
			if (rl - i >= 1 && rl - i <= n) s[i] = (a[rl - i] - a[i]) * b[i];
		for (int i = 1; i <= n; i++) s[i] += s[i - 1];
		for (int l = 1; l <= n; l++)
		{
			int r = rl - l;
			if (r < 1 || r < l || r > n) continue;
			ans = max(ans, sum + s[r] - s[l - 1]);
		}
	}
	cout << ans << "\n";
	return 0;
}