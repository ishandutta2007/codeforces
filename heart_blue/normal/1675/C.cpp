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
		int p0 = str.find('0');
		int p1 = str.find_last_of('1');
		if (p0 == str.npos && p1 == str.npos)
		{
			printf("%d\n", str.length());
		}
		else if (p0 != str.npos && p1 != str.npos)
		{
			printf("%d\n", max(1, p0 - p1 + 1));
		}
		else if (p0 != str.npos)
		{
			printf("%d\n", p0 + 1);
		}
		else if (p1 != str.npos)
		{
			printf("%d\n", str.length() - p1);
		}

	}

	return 0;
}