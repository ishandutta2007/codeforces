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
const int N = 8e3 + 10;
int a[N];
int flag[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;

	while (ncase--)
	{
		string str;
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;

		if (n1 == 0)
		{
			if (n0) puts(string(n0 + 1, '0').c_str());
			if (n2) puts(string(n2 + 1, '1').c_str());
			continue;
		}
		n0++, n2++;
		for (int i = 0; i <= n1; i++)
		{
			if (i & 1)
			{
				while (n2--) str += '1';
				n2 = 1;
			}
			else
			{
				while (n0--) str += '0';
				n0 = 1;
			}
		}
		puts(str.c_str());
	}
	return 0;
}