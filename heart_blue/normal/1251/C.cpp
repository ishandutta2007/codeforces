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
		string str;
		cin >> str;
		string v1, v2;
		for (auto& c : str)
		{
			if ((c - '0') & 1) v1.push_back(c);
			else v2.push_back(c);
		}
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		while (!v1.empty() && !v2.empty())
		{
			if (v1.back() < v2.back()) putchar(v1.back()), v1.pop_back();
			else putchar(v2.back()), v2.pop_back();
		}
		reverse(v1.begin(), v1.end());
		reverse(v2.begin(), v2.end());
		printf(v1.c_str());
		printf(v2.c_str());
		puts("");
	}
	return 0;
}