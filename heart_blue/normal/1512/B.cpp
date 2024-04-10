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
const int N = 3e1 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		map<int, int> mc1, mc2;
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < n; j++)
			{
				if (str[j] == '.') continue;
				mc1[i] = 1;
				mc2[j] = 1;
			}
		}
		if (mc1.size() == 1)
		{
			if (mc1.count(0)) mc1[1] = 1;
			else mc1[0] = 1;
		}
		if (mc2.size() == 1)
		{
			if (mc2.count(0)) mc2[1] = 1;
			else mc2[0] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mc1.count(i) && mc2.count(j)) putchar('*');
				else putchar('.');
			}
			puts("");
		}
	}
	return 0;
}