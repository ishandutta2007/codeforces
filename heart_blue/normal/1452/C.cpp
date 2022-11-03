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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		string str;
		int ans = 0;
		int o1 = 0, o2 = 0;
		cin >> str;
		for (auto& c : str)
		{
			if (c == '(') o1++;
			if (c == '[') o2++;
			if (c == ')')
			{
				if (o1 > 0) o1--, ans++;
			}
			if (c == ']')
			{
				if (o2 > 0) o2--, ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}