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
		int n;
		string str;
		cin >> n >> str;
		string s1, s2;
		int flag = 0;
		for (auto& c : str)
		{
			if (flag)
			{
				s1.push_back('0');
				s2.push_back(c);
				continue;
			}
			if (c == '0' || c == '2')
			{
				c = (c - '0') / 2 + '0';
				s1.push_back(c);
				s2.push_back(c);
			}
			else
			{
				char c2 = (c - '0') / 2 + '0';
				char c1 = c - c2 + '0';
				s1.push_back(c1);
				s2.push_back(c2);
				flag = 1;
			}
		}
		puts(s1.c_str());
		puts(s2.c_str());
	}
	return 0;
}