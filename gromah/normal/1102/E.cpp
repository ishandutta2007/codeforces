#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define Mod 998244353

int n, sz, ans = 1;
vector <int> Vec[N];
map <int, int> Map;

int main()
{
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		if (Map.find(x) == Map.end())
		{
			Vec[++ sz] = {i};
			Map.emplace(x, sz);
		}
		else Vec[Map[x]].push_back(i);
	}
	for (int i = 1, Max = Vec[1].back(); i < sz; i ++)
	{
		if (Vec[i + 1].front() > Max)
			ans = ans * 2 % Mod;
		Max = max(Max, Vec[i + 1].back());
	}
	printf("%d\n", ans);
	return 0;
}