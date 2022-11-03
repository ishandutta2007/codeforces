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
const int N = 3e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<pair<char, int>> vp;
	string str;
	cin >> str;
	for (auto& c : str)
	{
		if (vp.empty() || vp.back().first != c) vp.emplace_back(c, 1);
		else vp.back().second++;
	}
	if (vp.size() % 2 == 0) puts("0"), exit(0);
	int l = 0, r = vp.size() - 1;
	while (l < r)
	{
		if (vp[l].first != vp[r].first || vp[l].second + vp[r].second < 3) puts("0"), exit(0);
		l++, r--;
	}
	if (vp[l].second == 1) puts("0"), exit(0);
	cout << vp[l].second + 1 << endl;
	return 0;
}