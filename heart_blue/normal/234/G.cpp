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
const int N = 2e2 + 10;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<vector<int>> ans;
	int n;
	cin >> n;
	for (int o = 0; (n - 1) >> o; o++)
	{
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (i >> o & 1)
				v.push_back(i + 1);
		}
		ans.emplace_back(v);
	}
	printf("%d\n", ans.size());
	for (auto& v : ans)
	{
		printf("%d", v.size());
		for (auto& x : v) printf(" %d", x);
		puts("");
	}
	return 0;
}