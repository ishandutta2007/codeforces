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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int h1, a1, c1;
	int h2, a2;
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	vector<int> v;
	while (h2 > 0)
	{
		if (h2 <= a1)
		{
			v.push_back(0);
			break;
		}
		if (h1 <= a2)
		{
			v.push_back(1);
			h1 += c1 - a2;
		}
		else
		{
			v.push_back(0);
			h1 -= a2;
			h2 -= a1;
		}
	}
	vector<string> ans = { "STRIKE","HEAL" };
	printf("%d\n", v.size());
	for (auto &x : v)
	{
		puts(ans[x].c_str());
	}
	return 0;
}