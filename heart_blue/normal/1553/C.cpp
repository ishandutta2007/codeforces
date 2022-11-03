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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int solve(string str, char c)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '?') str[i] = c;
		c ^= 1;
	}
	int rest1 = 5, rest2 = 5;
	int cur1 = 0, cur2 = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '1')
		{
			if (i % 2 == 0) cur1++;
			else cur2++;
		}
		if (i % 2 == 0) rest1--;
		else rest2--;
		if (cur1 > rest2 + cur2) return i + 1;
		if (cur2 > rest1 + cur1) return i + 1;
	}
	return 10;
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
		cout << min(solve(str, '0'), solve(str, '1')) << endl;
	}
	return 0;
}