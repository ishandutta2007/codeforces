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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		string s[2];
		cin >> n >> s[0] >> s[1];
		int o = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[o][i] <= '2') continue;
			else
			{
				if (s[o ^ 1][i] <= '2')
				{
					o = -1;
					break;
				}
				o ^= 1;
			}
		}
		if (o == 1) puts("YES");
		else puts("NO");
	}
	return 0;
}