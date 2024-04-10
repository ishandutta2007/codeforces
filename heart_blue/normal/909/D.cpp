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
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	vector<pair<char, int>> vp;
	cin >> str;
	for (auto& c : str)
	{
		if (!vp.empty() && vp.back().first == c) vp.back().second++;
		else vp.emplace_back(c, 1);
	}
	int ans = 0;
	while (vp.size() > 1)
	{
		ans++;
		for (auto& p : vp)
			p.second -= 2;
		vp.front().second++;
		vp.back().second++;
		vector<pair<char, int>> key;
		for (auto [c, cnt] : vp)
		{
			if (cnt <= 0) continue;
			if (!key.empty() && key.back().first == c)
				key.back().second += cnt;
			else
				key.emplace_back(c, cnt);
		}
		vp.swap(key);
	}
	printf("%d\n", ans);
	return 0;
}