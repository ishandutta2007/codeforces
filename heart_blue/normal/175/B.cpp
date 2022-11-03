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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	map<string, int> ms;
	cin >> n;
	while (n--)
	{
		string str;
		int s;
		cin >> str >> s;
		ms[str] = max(ms[str], s);
	}
	n = ms.size();
	printf("%d\n", n);
	for (auto& p1 : ms)
	{
		int cnt = 0;
		for (auto& p2 : ms)
		{
			if (p2.second <= p1.second)
				cnt++;
		}
		printf(p1.first.c_str());
		if (cnt * 100 >= 99 * n) puts(" pro");
		else if (cnt * 100 >= 90 * n) puts(" hardcore");
		else if (cnt * 100 >= 80 * n) puts(" average");
		else if (cnt * 100 >= 50 * n) puts(" random");
		else puts(" noob");
	}
	return 0;
}