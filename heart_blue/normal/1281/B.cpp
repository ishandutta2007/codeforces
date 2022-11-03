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
	cin >> ncase;
	while (ncase--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int minv = min(s1.length(), s2.length());
		int flag = 0;
		for (int i = 0; i < minv; i++)
		{
			int key = i;
			for (int j = i + 1; j < s1.length(); j++)
			{
				if (s1[j] <= s1[key])
				{
					key = j;
				}
			}
			if (s1[i] != s1[key])
			{
				swap(s1[i], s1[key]);
				break;
			}
			if (s1[i] != s2[i]) break;
		}
		if (s1 < s2) puts(s1.c_str());
		else puts("---");
	}
	return 0;
}