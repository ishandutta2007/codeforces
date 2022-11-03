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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		string ans;
		cin >> n;
		vector<pair<int, int>> vp;
		vp.emplace_back(0, 0);
		while (n--)
		{
			int x, y;
			cin >> x >> y;
			vp.emplace_back(x, y);
		}
		sort(vp.begin(), vp.end());
		for (int i = 1; i< vp.size(); i++)
		{
			auto p1 = vp[i - 1];
			auto p2 = vp[i];
			if (p1.second > p2.second)
			{
				ans.clear();
				break;
			}
			ans += string(p2.first - p1.first, 'R') + string(p2.second - p1.second, 'U');
		}
		if (ans.empty()) puts("NO");
		else puts("YES"), puts(ans.c_str());
	}
	return 0;
}