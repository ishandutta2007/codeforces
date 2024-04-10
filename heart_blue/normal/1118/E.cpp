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
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ans;
	for (int i = 1; i <= k; i++)
	{
		for (int j = i + 1; j <= k && n > 0; n -= 2, j++)
		{
			ans.emplace_back(i, j);
			ans.emplace_back(j, i);
		}
	}
	if (n < 0) ans.pop_back();
	if (n > 0) puts("NO"), exit(0);
	puts("YES");
	for (auto& p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}