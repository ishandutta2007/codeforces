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
vector<pair<int, int>> v1, v2;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int o, x;
		cin >> o >> x;
		if (o == 0) v1.push_back({ i,x });
		else v2.push_back({ i,x });
	}
	int ptr = 0;
	for (auto &p : v1)
	{
		int x, pos;
		tie(pos, x) = p;
		while (ptr < v2.size() && v2[ptr].second <= x)
		{
			flag[pos] = 1;
			printf("%d %d %d\n", v2[ptr].first, pos, v2[ptr].second);
			x -= v2[ptr++].second;
		}

		if (ptr != v2.size())
			printf("%d %d %d\n", pos, v2[ptr].first, x), flag[pos] = 1, v2[ptr].second -= x;
		if (flag[pos] == 0)
			printf("%d %d %d\n", pos, v2.back().first, 0);
	}
	return 0;
}