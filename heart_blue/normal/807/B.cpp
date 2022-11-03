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
const int N = 1e5 + 10;
bool check(int s, int p)
{
	int i = (s / 50) % 475;
	int cnt = 25;
	while (cnt--)
	{
		i = (i * 96 + 42) % 475;
		if (i + 26 == p) return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int p, x, y;
	cin >> p >> x >> y;
	for (int i = 0; ; i++)
	{
		int o = x;
		while (o >= y)
		{
			if (check(o, p))
			{
				cout << i << endl;
				return 0;
			}
			o -= 50;
		}
		x += 100;
	}
	return 0;
}