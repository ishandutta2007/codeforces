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
#include <iterator>
#include <complex>
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
bool solve1(string& str)
{
	int key = -1;
	for (int i = 0; i + 1 < str.length(); i++)
	{
		int x = str[i] - '0';
		int y = str[i + 1] - '0';
		if (x + y > 9)
			key = i;
	}
	if (key == -1) return false;
	cout << str.substr(0, key)
		<< str[key] - '0' + str[key + 1] - '0'
		<< str.substr(key + 2) << '\n';
	return true;
}
void solve2(string& str)
{
	int key = -1;
	for (int i = 0; i + 1 < str.length(); i++)
	{
		int x = str[i] - '0';
		int y = str[i + 1] - '0';
		if (x + y > x)
		{
			cout << str.substr(0, i) << char(x + y + '0') << str.substr(i + 2) << '\n';
			return;
		}
	}
	str.pop_back();
	cout << str << '\n';
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		cin >> str;
		if (solve1(str))
			continue;
		solve2(str);
	}
	return 0;
}