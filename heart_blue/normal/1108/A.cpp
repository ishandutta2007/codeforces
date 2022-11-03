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
const int N = 1e6 + 10;
pair<int, int> check(int l1, int r1, int l2, int r2)
{
	for (int i = l1; i <= r1; i++)
	{
		for (int j = l2; j <= r2; j++)
		{
			if (i != j)
			{
				return { i,j };
			}
		}
	}
	return { -1,-1 };
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	while (q--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int x, y;
		tie(x, y) = check(l1, r1, l2, r2);
		printf("%d %d\n", x, y);
	}
	return 0;
}