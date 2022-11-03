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
void refrain(string& str, int p)
{
	for (int i = p; i < str.length(); i++) str[i] = str[i - p];
	for (int i = str.length() - 1; i > 0; i--)
	{
		if (str[i] > '9') str[i] -= 10, str[i - 1] ++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int p;
	cin >> p;
	string str;
	cin >> str;
	if (count(str.begin(), str.end(), '9') == str.length())
	{
		str = "1" + string(str.length(), '0');
	}
	else
	{
		str.back()++;
		for (int i = str.length() - 1; i > 0; i--)
		{
			if (str[i] > '9') str[i] -= 10, str[i - 1] ++;
		}
	}
	if (str.length() % p)
	{
		string ans = "1" + string(p - 1, '0');
		while (ans.length() < str.length() || ans.length() % p != 0)
		{
			char c = ans[ans.length() - p];
			ans.push_back(c);
		}
		puts(ans.c_str());
		return 0;
	}
	string ans = str;
	refrain(ans, p);
	if (ans >= str)
	{
		puts(ans.c_str());
		return 0;
	}
	ans[p - 1]++;
	refrain(ans, p);
	puts(ans.c_str());
	return 0;
}