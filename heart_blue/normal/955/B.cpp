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
const int N = 4e6 + 10;
const int M = 2e7 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	map<char, int> mc;
	for (auto &c : str) mc[c]++;
	vector<int> v;
	for (auto &p : mc) v.push_back(p.second);
	sort(v.begin(), v.end());
	if (mc.size() > 4 ||mc.size() == 1)
	{
		puts("No");
		return 0;
	}
	if (mc.size() == 3)
	{
		if (v.back() > 1) puts("Yes");
		else puts("No");
		return 0;
	}
	if (mc.size() == 2)
	{
		if (v.front() > 1) puts("Yes");
		else puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}