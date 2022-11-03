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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	for (auto &c : str) if (c == ',') c = ' ';
	stringstream sin(str);
	int x;
	map<int, int> mc;
	while (sin >> x)
	{
		mc[x] = 1;
	}
	vector<pair<int, int>> ans;
	for (auto &p : mc)
	{
		if (!ans.empty() && ans.back().second == p.first - 1) ans.back().second++;
		else ans.push_back({ p.first,p.first });
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (i) putchar(',');
		if (ans[i].first == ans[i].second) printf("%d", ans[i].first);
		else printf("%d-%d", ans[i].first, ans[i].second);
	}
	return 0;
}