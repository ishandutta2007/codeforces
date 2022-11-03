#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL fact[N];
LL rfact[N];
LL dp[N];
void init()
{
	rfact[0] = rfact[1] = 1;
	for (int i = 0; i < N; i++) fact[i] = i;
	fact[0] = 1;
	for (int i = 2; i < N; i++)
	{
		rfact[i] = (INF - INF / i)*rfact[INF%i] % INF;
	}
	for (int i = 1; i < N; i++)
	{
		fact[i] = (fact[i] * fact[i - 1]) % INF;
	}
	for (int i = 1; i < N; i++)
	{
		rfact[i] = (rfact[i] * rfact[i - 1]) % INF;
	}
}
LL C(int n, int m)
{
	return fact[n] * rfact[n - m] % INF*rfact[m] % INF;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h, w, n;
	init();
	cin >> h >> w >> n;
	vector<pair<int, int>> vp(n);
	for (auto &p : vp)
	{
		cin >> p.first >> p.second;
	}
	vp.push_back({ h,w });
	vp.push_back({ 1,1 });
	sort(vp.begin(), vp.end());
	n++;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		tie(x, y) = vp[i];
		dp[i] = C(x - 1 + y - 1, x - 1);
		for (int j = 1; j < i; j++)
		{
			int ox, oy;
			tie(ox, oy) = vp[j];
			if (ox <= x && oy <= y)
			{
				dp[i] -= dp[j] * C(x - ox + y - oy, x - ox)%INF;
				if (dp[i] < 0) dp[i] += INF;
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}