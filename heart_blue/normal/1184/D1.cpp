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
const int N = 4e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, m, t;
	cin >> n >> k >> m >> t;
	while (t--)
	{
		int op, x;
		cin >> op >> x;
		if (op == 0)
		{
			if (k <= x)
			{
				n = x;
			}
			else
			{
				n -= x;
				k -= x;
			}
		}
		else
		{
			if (k >= x) k++;
			n++;
		}
		cout << n << ' ' << k << endl;
	}
	return 0;
}