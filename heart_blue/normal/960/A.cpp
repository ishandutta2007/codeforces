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
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	map<char, int> mc;
	for (auto &c : str) mc[c]++;
	if (mc.size() != 3)
	{
		puts("NO");
		return 0;
	}
	string s1 = str;
	sort(s1.begin(), s1.end());
	if (s1 != str)
	{
		puts("NO");
		return 0;
	}
	if (mc['c'] == mc['a'] || mc['c'] == mc['b'])
	{
		puts("YES");
	}
	else puts("NO");
	return 0;
}