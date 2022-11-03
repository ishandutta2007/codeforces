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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, p;
	cin >> n >> p;
	string str;
	cin >> str;
	int flag = 0;
	for (int i = 0; i + p < n; i++)
	{
		char &x = str[i];
		char &y = str[i + p];
		if (x == '.' || y == '.')
		{
			if (x == '.' && y == '.') x = '0';
			if (x == '.') x = y ^ 1;
			if (y == '.') y = x ^ 1;
			flag = 1;
			break;
		}
		if (x != y)
		{
			flag = 1;
			break;
		}
	}
	if (!flag)
	{
		puts("No");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '.') str[i] = '0';
	}
	puts(str.c_str());
	return 0;
}