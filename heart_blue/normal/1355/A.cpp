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
const int N = 1e6 + 10;
const LL INF = 1e9 + 7;

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
		LL k;
		cin >> k;
		while (--k)
		{
			int minv = 9, maxv = 0;
			for (auto& c : str)
			{
				minv = min(minv, c - '0');
				maxv = max(maxv, c - '0');
			}
			if (minv == 0) break;
			LL ans = stoll(str) + minv * maxv;
			str = to_string(ans);
		}
		puts(str.c_str());
	}
	return 0;
}