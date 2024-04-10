#include <iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int inf = -9999909;

void solve()
{
	int r, n;
	cin >> r >> n;
	int bnd = 4 * r + 8;
	vector<int> dp(n + 1, inf);
	dp[0] = 0;
	vector<vector<int>> points(n + 1, vector<int>(3));
	points[0] = {1, 1, 0};
	for (int i = 1; i <= n; i++)
	{
		int x, y, t;
		cin >> t >> x >> y;
		points[i] = {x, y, t};
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = max(0, i - bnd); j < i; j++)
		{
			if (abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) <= points[i][2] - points[j][2])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
		//cout<<i<<' '<<dp[i]<<endl;
	}
	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}