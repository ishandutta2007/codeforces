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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<char, int> mc;
	mc['a'] = 1;
	mc['e'] = 1;
	mc['u'] = 1;
	mc['i'] = 1;
	mc['o'] = 1;
	mc['n'] = 2;
	string str;
	cin >> str;
	int n = str.length();
	str.push_back('s');
	for (int i = 0; i < n; i++)
	{
		if (mc[str[i]] == 0 && mc[str[i + 1]] != 1)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}