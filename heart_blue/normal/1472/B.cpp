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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int n;
		cin >> n;
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x == 1) a++;
			else b++;
		}
		int tot = a + b * 2;
		int flag = 0;
		for (int i = 0; i <= a; i++)
		{
			for (int j = 0; j <= b; j++)
			{
				if (i * 2 + j * 4 == tot)
					flag = 1;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}