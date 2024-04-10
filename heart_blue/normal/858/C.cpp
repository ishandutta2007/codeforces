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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s = "aeiou";
	for (auto &c : s) flag[c] = 1;
	string str;
	cin >> str;
	map<char, int> mc;
	int cnt = 0;
	for (auto &c : str)
	{
		if (flag[c])
		{
			putchar(c);
			mc.clear();
			cnt = 0;
			continue;
		}
		mc[c] = 1;
		cnt++;
		if (cnt >= 3 && mc.size() > 1)
		{
			putchar(' ');
			cnt = 1;
			mc.clear();
			mc[c] = 1;
		}
		putchar(c);
	}
	return 0;
}