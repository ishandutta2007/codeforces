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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		cin >> n;
		int flag = 0;
		map<string, int> ms2, ms3;
		while (n--)
		{
			string str;
			cin >> str;
			if (flag) continue;
			if (str.front() == str.back())
			{
				flag = 1;
				continue;
			}
			if (str.length() == 2 &&
				(ms2.count(str) || ms3.count(str)))
			{
				flag = 1;
				continue;
			}
			if (str.length() == 3 &&
				(ms2.count(str.substr(1))) || ms3.count(str))
			{
				flag = 1;
			}
			reverse(str.begin(), str.end());
			if (str.length() == 3) ms3[str.substr(1)] = 1, ms3[str] = 1;
			else ms2[str] = 1;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}