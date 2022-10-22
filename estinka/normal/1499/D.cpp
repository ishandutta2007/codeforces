#include <iostream>
#include <string>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <queue>
typedef long long ll;
using namespace std;

// g * (c * a' * b' - d) = x
// a' * b' = (x / g + d) / c
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int C = 2e7 + 128;
	//const int C = 128;
	vector<int> pr, lp(C, 1), divcnt(C, 1);
	divcnt[1] = 1;
	for (int i = 2; i < C; i++)
	{
		if (lp[i] == 1) lp[i] = i, pr.push_back(i);
		if (lp[i / lp[i]] != lp[i]) divcnt[i] = divcnt[i / lp[i]] << 1;
		else divcnt[i] = divcnt[i / lp[i]];
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i < C; j++)  lp[i * pr[j]] = pr[j];
	}
	int t;
	cin >> t;
	while (t--)
	{
		int c, d, x;
		cin >> c >> d >> x;
		vector<int> dv;
		for (int i = 1; i * i <= x; i++)
		{
			if (x % i == 0)
			{
				dv.push_back(i);
				if (i * i != x) dv.push_back(x / i);
			}
		}
		ll ans = 0;
		for (int g : dv)
		{
			int ab = x / g + d;
			if (ab % c) continue;
			ab /= c;
			ans += divcnt[ab];
		}
		cout << ans << "\n";
	}
	return 0;
}