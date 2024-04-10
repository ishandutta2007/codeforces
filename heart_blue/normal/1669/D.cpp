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
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int cnt0 = 0, cnt1 = 0;
		int n;
		scanf("%d", &n);
		string str;
		cin >> str;
		str += 'W';
		int ok = 1;
		for (auto& c : str)
		{
			if (c == 'B') cnt1++;
			else if (c == 'R') cnt0++;
			else
			{
				if (cnt1 == 0 && cnt0 == 0) continue;
				if (cnt1 * cnt0 == 0) ok = 0;
				cnt1 = cnt0 = 0;
			}
		}
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;

}