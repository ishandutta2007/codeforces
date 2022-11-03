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
const int N = 1e4 + 10;
map<vector<int>, int> ms;
int pos[N];
void init()
{
	pos['A'] = 0;
	pos['2'] = 1;
	pos['3'] = 2;
	pos['4'] = 3;
	pos['5'] = 4;
	pos['6'] = 5;
	pos['7'] = 6;
	pos['8'] = 7;
	pos['9'] = 8;
	pos['T'] = 9;
	pos['J'] = 10;
	pos['Q'] = 11;
	pos['K'] = 12;
	pos['S'] = 0;
	pos['D'] = 13;
	pos['H'] = 26;
	pos['C'] = 39;
}
inline bool check(int x, int y)
{
	return x % 13 == y % 13 || x / 13 == y / 13;
}
int check(vector<int>& v)
{
	if (v.size() == 1) return true;
	if (ms.count(v)) return ms[v];
	auto& ret = ms[v] = 0;
	int key = v.size() - 1;
	for (int i = -1; i >= -3; i -= 2)
	{
		if (key + i < 0) continue;
		if (check(v[key], v[key + i]))
		{
			int x = v[key + i], y = v[key];
			v[key + i] = y;
			v.pop_back();
			ret |= check(v);
			v[key + i] = x;
			v.push_back(y);
			if (ret) break;
		}
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v)
	{
		string s;
		cin >> s;
		x = pos[s[0]] + pos[s[1]];
	}
	if (check(v)) puts("YES");
	else puts("NO");
	return 0;
}