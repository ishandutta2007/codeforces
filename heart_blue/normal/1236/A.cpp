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
const LL INF = 1e8 + 7;
const int N = 2e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for (int i = 0; i <= a && i * 2 <= b; i++)
		{
			for (int j = 0; i * 2 + j <= b && j * 2 <= c; j++)
			{
				ans = max(ans, (i + j) * 3);
			}
		}
		cout << ans << endl;
	}
	return 0;
}