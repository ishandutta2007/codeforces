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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		string str;
		cin >> str;
		str += '0';
		LL dp0 = b, dp1 = INF * INF;
		for(int i  = 1; i < str.length(); i++)
		{
			int c = '0' + (str[i - 1] == '1' || str[i] == '1');
			if (c == '0')
			{
				tie(dp0, dp1) = make_pair(min(dp0 + a + b, dp1 + 2 * a + b),
					min(dp0 + 2 * a + 2 * b, dp1 + a + 2 * b)
				);
			}
			else
			{
				dp1 = min(dp0 + 2 * a + 2 * b, dp1 + a + 2 * b);
				dp0 = INF * INF;
			}
		}
		cout << dp0 << endl;
	}
	return 0;
}