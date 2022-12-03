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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
LL ask(int a, int b)
{
	cout << "? " << a << ' ' << b << endl;
	LL ret;
	cin >> ret;
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int ans = 0;
		for (int i = 0; i < 30; i++)
		{
			if (ask(-ans + (1 << i), -ans + (1 << i) + (1LL << (i + 1))) == 1LL << (i + 1))
			{
				ans |= 1 << i;
			}
		}
		cout << "! " << ans << endl;
	}
	return 0;
}