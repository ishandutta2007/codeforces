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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int px, py;
		scanf("%d%d", &px, &py);
		int l = 0, r = 0, u = 0, d = 0;
		string str;
		cin >> str;
		for (auto& c : str)
		{
			if (c == 'U') u++;
			if (c == 'D') d++;
			if (c == 'R') r++;
			if (c == 'L') l++;
		}
		if (px < 0) px = -px, swap(l, r);
		if (py < 0) py = -py, swap(u, d);
		if (px <= r && py <= u) puts("YES");
		else puts("NO");
	}
	return 0;
}