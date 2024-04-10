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
const int N = 1e5 + 10;
int x, a, b, c;
int gen()
{
	x = (x * a + b) % c;
	return x;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	vector<pair<int, string>> vp;
	int n;
	cin >> n;
	cin >> x >> a >> b >> c;
	for (int i = 0; i < n; i++)
	{
		string name;
		int val;
		cin >> name >> val;
		vp.emplace_back(val, name);
	}
	sort(vp.rbegin(), vp.rend());
	for (int o = n / 4; o >= 1; o--)
	{
		printf("Group %c:\n", char('A' + (n / 4 - o)));
		int d = o - 1;
		for (int i = 0; i < 4; i++)
		{
			int pos = gen() % o;
			auto iter = vp.begin() + i * d + pos;
			puts(iter->second.c_str());
			vp.erase(iter);
		}
	}
	return 0;
}